#ifndef PARSER_H
#define PARSER_H

#include <QThread>
#include <QMutex>
#include <QtGui>

// OpenCV header files
#include <opencv/highgui.h>

class FrameBuffer;

using namespace cv;

class Parser : public QThread
{
    Q_OBJECT

public:
    Parser(FrameBuffer *buffer);
    ~Parser();
    void stopParsing();

protected:
    void run();

private:
    FrameBuffer *buffer;
    Mat frame;
    QMutex alt;
    QImage currentFrame;
    volatile bool stopped;

signals:
    void newFrame(const QImage &frame);

};

#endif // PARSER_H
