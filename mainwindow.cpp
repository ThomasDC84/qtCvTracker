#include "mainwindow.h"
#include "functions.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    setupActions();
    this->comboBox->addItems(getAvailableDevices());
}

void MainWindow::setupActions()
{
    connect(this->exitAction, SIGNAL(triggered()), this, SLOT(close()));
    connect(this->aboutQtAction, SIGNAL(triggered()), this, SLOT(aboutQt()));
    videoManager = new VideoManager();
    connect(comboBox, SIGNAL(currentIndexChanged(int)), videoManager, SLOT(setDevice(int)));
    connect(btnConnect, SIGNAL(clicked()), videoManager, SLOT(connectToDevice()));
    connect(btnDisconnect, SIGNAL(clicked()), videoManager, SLOT(disconnectFromDevice()));
    connect(videoManager, SIGNAL(newFrame(QImage)), this, SLOT(updateFrame(QImage)));
}

void MainWindow::updateFrame(const QImage &frame)
{
    label->setPixmap(QPixmap::fromImage(frame));
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this);
}

MainWindow::~MainWindow()
{
    delete videoManager;
}
