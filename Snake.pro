#-------------------------------------------------
#
# Project created by QtCreator 2015-07-08T09:11:54
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    gamefield.cpp \
    field.cpp \
    fruit.cpp \
    game.cpp \
    painter.cpp \
    scene.cpp \
    snake.cpp \
    ceratefield.cpp

HEADERS  += menu.h \
    gamefield.h \
    field.h \
    fruit.h \
    game.h \
    painter.h \
    scene.h \
    snake.h \
    ceratefield.h

FORMS    += menu.ui \
    gamefield.ui \
    ceratefield.ui

RESOURCES += \
    shaders.qrc
