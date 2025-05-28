QT       += core gui

#我的添加模块
QT       += network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    baidumap.cpp \
    main.cpp \
    music.cpp \
    video.cpp \
    widget.cpp

HEADERS += \
    baidumap.h \
    music.h \
    video.h \
    widget.h

FORMS += \
    baidumap.ui \
    music.ui \
    video.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Src.qrc
