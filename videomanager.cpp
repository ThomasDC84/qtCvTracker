#include "videomanager.h"
#include <QDebug>

VideoManager::VideoManager()
{
    device = 0;
}

void VideoManager::setDevice(int deviceID)
{
    device = deviceID;
}

void VideoManager::connectToDevice()
{
    buffer = new FrameBuffer(20);
    stream = new VideoStream(buffer);
    parser = new Parser(buffer);
    stream->connectToDevice(device);
    stream->start();
    parser->start();
    connect(parser, SIGNAL(newFrame(QImage)), SIGNAL(newFrame(QImage)));
}

void VideoManager::disconnectFromDevice()
{
    if(parser->isRunning())
    {
        qDebug() << "parser running";
        parser->stopParsing();
        parser->wait();
        qDebug() << "no more";
    }
    if(stream->isRunning())
    {
        qDebug() << "stream running";
        stream->stopStream();
        stream->disconnectFromDevice();
        stream->wait();
        qDebug() << "no more";
    }
    delete parser;
    delete stream;
    buffer->clearBuffer();
    delete buffer;
    emit newFrame(QImage());
}

VideoManager::~VideoManager()
{
    disconnectFromDevice();
}
