TEMPLATE = lib
TARGET = ../selector
INCLUDEPATH += $${PWD} $${PWD}/..
HEADERS = \
    $$PWD/polygonSelect.h \
    $$PWD/commands.h \
    $$PWD/ellipseSelect.h \
    $$PWD/photoScene.h \
    $$PWD/rectangleSelect.h \
    $$PWD/selectItem.h \
    $$PWD/freeDrawSelect.h \
    boxbasedselector.h \
    label.h \
    freeDrawErase.h

SOURCES = \
    $$PWD/polygonSelect.cpp \
    $$PWD/commands.cpp \
    $$PWD/ellipseSelect.cpp \
    $$PWD/photoScene.cpp \
    $$PWD/rectangleSelect.cpp \
    $$PWD/selectItem.cpp \
    $$PWD/freeDrawSelect.cpp \
    boxbasedselector.cpp \
    label.cpp \
    freeDrawErase.cpp

LIBS += -lQt5Widgets

QT += core gui widgets network
