#include "framebuffer.h"

FrameBuffer::FrameBuffer(int size)
{
    bufferSize = size;
    freeBuffer = new QSemaphore(size);
    usedBuffer = new QSemaphore(0);
}

void FrameBuffer::addFrame(const Mat& frame)
{
    freeBuffer->acquire();
    bufferMutex.lock();
    frameQueue.enqueue(frame);
    bufferMutex.unlock();
    usedBuffer->release();
}

Mat FrameBuffer::getFrame()
{
    usedBuffer->acquire();
    Mat retFrame;
    bufferMutex.lock();
    retFrame = frameQueue.dequeue();
    bufferMutex.unlock();
    freeBuffer->release();
    return retFrame.clone();
}

void FrameBuffer::clearBuffer()
{
    if(frameQueue.size() != 0)
    {
        freeBuffer->release(frameQueue.size());
        freeBuffer->acquire(bufferSize);
        usedBuffer->acquire(frameQueue.size());
        bufferMutex.lock();
        frameQueue.clear();
        bufferMutex.unlock();
        freeBuffer->release(bufferSize);
    }
}
