#-------------------------------------------------
#
# Project created by QtCreator 2017-05-05T10:48:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseballStadiumPlanner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    date.cpp \
    stadiuminfo.cpp \
    listwindow.cpp \
    tripwindow.cpp \
    adminlogin.cpp \
    adminfuntion.cpp

HEADERS  += mainwindow.h \
    binarytree.h \
    stadiuminfo.h \
    date.h \
    listwindow.h \
    tripwindow.h \
    adminlogin.h \
    adminfuntion.h

FORMS    += mainwindow.ui \
    listwindow.ui \
    tripwindow.ui \
    adminlogin.ui \
    adminfuntion.ui

CONFIG += c++11
