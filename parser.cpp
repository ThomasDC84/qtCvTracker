#include "parser.h"
#include "framebuffer.h"
#include "MatToQImage.h"

Parser::Parser(FrameBuffer *buffer) : QThread(), buffer(buffer)
{
    stopped = false;
}

Parser::~Parser()
{
    //suicide
}

void Parser::run()
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
        frame = buffer->getFrame();
        currentFrame = MatToQImage(frame);
        emit newFrame(currentFrame);
    }
    emit newFrame(QImage());
}

void Parser::stopParsing()
{
    alt.lock();
    stopped = true;
    alt.unlock();
}
