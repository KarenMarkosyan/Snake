#-------------------------------------------------
#
# Project created by QtCreator 2015-07-08T09:11:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    gamefield.cpp \
    field.cpp \
    Fruit.cpp \
    Game.cpp \
    Painter.cpp \
    Scene.cpp \
    Snake.cpp \
    Painter.cpp

HEADERS  += menu.h \
    gamefield.h \
    field.h \
    Fruit.h \
    Game.h \
    Painter.h \
    Scene.h \
    Snake.h \
    Painter.h
	

FORMS    += menu.ui \
    gamefield.ui

RESOURCES += \
    Shaders.qrc
