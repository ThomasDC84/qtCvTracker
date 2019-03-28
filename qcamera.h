#ifndef QCAMERA_H
#define QCAMERA_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

class QCamera : public QObject
{
    Q_OBJECT
public:
    explicit QCamera(QObject *parent = 0);
    bool connectToCamera(int device);
    int getCameraID();
    bool isConnected();
    void disconnectCamera();
    Mat getCurrentFrame();
    ~QCamera();

private:
    VideoCapture cap;
    Mat frame;
    int cameraID;
    
signals:
    
public slots:
    
};

#endif // QCAMERA_H
