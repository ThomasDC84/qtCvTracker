#include "main.h"
#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //setup Internazionalization
    QTranslator translator;
    QString filename;
    filename = QString("qtcvtracker_%1").arg(QLocale::system().name());
    filename = filename.toLower();
    translator.load(filename);
    a.installTranslator(&translator);

    //setup application info
    QApplication::setApplicationName("qtCvTracker");
    QApplication::setApplicationVersion("1.0");
    QApplication::setOrganizationName("Dev(il) Team");
    QApplication::setOrganizationDomain("qtCvTracker.org");

    MainWindow w;
    w.show();
    
    return a.exec();
}
