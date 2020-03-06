#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T10:56:17
#
#-------------------------------------------------

QT       += core gui
QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    morpher.cpp \
    morphingselect.cpp \
    imageinfomainwindow.cpp \
    cannymianwindow.cpp \
    bmpimage.cpp \
    capturescreen.cpp \
    templatematch.cpp

HEADERS += \
        mainwindow.h \
    morpher.h \
    morphingselect.h \
    imageinfomainwindow.h \
    cannymianwindow.h \
    bmpimage.h \
    capturescreen.h \
    templatematch.h

FORMS += \
        mainwindow.ui \
    morphingselect.ui \
    imageinfomainwindow.ui \
    cannymianwindow.ui

INCLUDEPATH += F:\software\opencv343Build\include\opencv\
                F:\software\opencv343Build\include\opencv2\
                F:\software\opencv343Build\include

LIBS += F:\software\opencv343Build\lib\libopencv_*.dll.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
