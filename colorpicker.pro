QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorPicker
TEMPLATE = app
CONFIG += c++11

HEADERS +=  \
    colorcircle.h \
    colortank.h


SOURCES += \
    colorcircle.cpp \
    colortank.cpp \
    main.cpp
