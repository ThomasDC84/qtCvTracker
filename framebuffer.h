#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

// Qt header files
#include <QMutex>
#include <QQueue>
#include <QSemaphore>
// OpenCV header files
#include <opencv/highgui.h>

using namespace cv;

class FrameBuffer
{

public:
    explicit FrameBuffer(int size);
    void addFrame(const Mat& frame);
    Mat getFrame();
    void clearBuffer();

private:
    QSemaphore *freeBuffer;
    QSemaphore *usedBuffer;
    QMutex bufferMutex;
    QQueue<Mat> frameQueue;
    int bufferSize;
    
};

#endif // FRAMEBUFFER_H
