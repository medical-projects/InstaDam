#-------------------------------------------------
#
# Project created by QtCreator 2019-02-01T18:48:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InstaDam
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

CONFIG += c++1z

SOURCES += \
        main.cpp \
        instadam.cpp \
        label.cpp \
        project.cpp \
        maskviewer.cpp \
        photoviewer.cpp \
    pixmapops.cpp \
    filterproperty.cpp \
    filters.cpp \
    picpushbutton.cpp \
    maskobjects.cpp \
    filtercontrols.cpp \
    fslider.cpp \
    newproject.cpp \
    labelbutton.cpp \
    paintbrush.cpp

HEADERS += \
        instadam.h \
        label.h \
        project.h \
        photoviewer.h \
        maskviewer.h \
    pixmapops.h \
    filterproperty.h \
    filters.h \
    picpushbutton.h \
    maskobjects.h \
    filtercontrols.h \
    filterproperty.h \
    fslider.h \
    newproject.h \
    labelbutton.h \
    paintbrush.h


FORMS += \
        instadam.ui \
    newproject.ui

INCLUDEPATH += D:\opencv\opencv\build\include

LIBS += D:\opencv\opencv-build32\bin\libopencv_core320.dll
LIBS += D:\opencv\opencv-build32\bin\libopencv_highgui320.dll
LIBS += D:\opencv\opencv-build32\bin\libopencv_imgcodecs320.dll
LIBS += D:\opencv\opencv-build32\bin\libopencv_imgproc320.dll
LIBS += D:\opencv\opencv-build32\bin\libopencv_features2d320.dll
LIBS += D:\opencv\opencv-build32\bin\libopencv_calib3d320.dll


# more correct variant, how set includepath and libs for mingw
# add system variable: OPENCV_SDK_DIR=D:/opencv/build
# read http://doc.qt.io/qt-5/qmake-variable-reference.html#libs

#INCLUDEPATH += $$(OPENCV_SDK_DIR)/include

#LIBS += -L$$(OPENCV_SDK_DIR)/x86/mingw/lib \
#        -lopencv_core320        \
#        -lopencv_highgui320     \
#        -lopencv_imgcodecs320   \
#        -lopencv_imgproc320     \
#        -lopencv_features2d320  \
#        -lopencv_calib3d320


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


