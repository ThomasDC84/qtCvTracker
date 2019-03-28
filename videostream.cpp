#include "videostream.h"
#include "framebuffer.h"

VideoStream::VideoStream(FrameBuffer *buffer) :
    QThread(), buffer(buffer)
{
    stopped = false;
}

VideoStream::~VideoStream()
{
    disconnectFromDevice();
}

void VideoStream::run()
{
    forever
    {
        alt.lock();
        if(stopped)
        {
            stopped = false;
            alt.unlock();
            break;
        }
        alt.unlock();
        cap >> newFrame;
        buffer->addFrame(newFrame);
    }
}

bool VideoStream::connectToDevice(int device)
{
    return cap.open(device);
}

void VideoStream::disconnectFromDevice()
{
    if(cap.isOpened())
    {
        cap.release();
    }
}

bool VideoStream::isConnected()
{
    return cap.isOpened();
}

void VideoStream::stopStream()
{
    alt.lock();
    stopped=true;
    alt.unlock();
}
