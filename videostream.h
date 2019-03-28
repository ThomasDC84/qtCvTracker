#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H

// Qt header files
#include <QThread>
#include <QMutex>
// OpenCV header files
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

class FrameBuffer;

class VideoStream : public QThread
{
    Q_OBJECT

public:
    explicit VideoStream(FrameBuffer *buffer);
    ~VideoStream();
    bool connectToDevice(int device);
    void disconnectFromDevice();
    bool isConnected();
    void stopStream();

protected:
    void run();

private:
    CvCapture* capture;
    FrameBuffer *buffer;
    VideoCapture cap;
    Mat newFrame;
    QMutex alt;
    volatile bool stopped;
    
signals:
    
public slots:
    
};

#endif // VIDEOSTREAM_H
