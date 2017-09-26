#-------------------------------------------------
#
# Project created by QtCreator 2017-09-18T13:30:40
#
#-------------------------------------------------

QT       += core gui
QT       += opengl


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengl_linux
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h
