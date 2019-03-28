#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "videomanager.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void setupActions();
    ~MainWindow();

private:
    VideoManager *videoManager;

public slots:
    void updateFrame(const QImage &frame);
    void aboutQt();
};

#endif // MAINWINDOW_H
