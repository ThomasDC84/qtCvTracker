#-------------------------------------------------
#
# Project created by QtCreator 2013-04-03T17:16:17
#
#-------------------------------------------------

QT       += gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtCvTracker
TEMPLATE = app
VERSION = 1.0


SOURCES += main.cpp\
        mainwindow.cpp \
    MatToQImage.cpp \
    framebuffer.cpp \
    videostream.cpp \
    parser.cpp \
    videomanager.cpp \
    functions.cpp

HEADERS  += mainwindow.h \
    version.h \
    MatToQImage.h \
    main.h \
    framebuffer.h \
    videostream.h \
    parser.h \
    videomanager.h \
    functions.h

FORMS    += mainwindow.ui

TRANSLATIONS =  qtcvtracker_it.ts \
                qtcvtracker_de.ts \
                qtcvtracker_fr.ts

OTHER_FILES = resources.rc
RC_FILE = resources.rc

#two configuration: release and debug
CONFIG(release,debug|release){
    INCLUDEPATH += "$$(OPENCV_BUILD)/release/include"
    LIBS += -L$$(OPENCV_BUILD)/release/lib/ \
            -lopencv_core$$(OPENCV_VER) \
            -lopencv_imgproc$$(OPENCV_VER) \
            -lopencv_highgui$$(OPENCV_VER)
}

CONFIG(debug,debug|release){
    INCLUDEPATH += "$$(OPENCV_BUILD)/debug/include"
    LIBS += -L$$(OPENCV_BUILD)/debug/lib/ \
            -lopencv_core$$(OPENCV_VER)d \
            -lopencv_imgproc$$(OPENCV_VER)d \
            -lopencv_highgui$$(OPENCV_VER)d
}
