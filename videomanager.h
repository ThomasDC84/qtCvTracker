#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H

#include "framebuffer.h"
#include "videostream.h"
#include "parser.h"

#include <QtGui>

class VideoManager : public QObject
{
    Q_OBJECT

public:
    explicit VideoManager();
    ~VideoManager();

private:
    int device;
    FrameBuffer *buffer;
    VideoStream *stream;
    Parser *parser;

signals:
    void newFrame(const QImage &frame);

public slots:
    void setDevice(int deviceID);
    void connectToDevice();
    void disconnectFromDevice();

};

#endif // VIDEOMANAGER_H
