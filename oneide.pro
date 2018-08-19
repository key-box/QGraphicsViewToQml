#-------------------------------------------------
#
# Project created by QtCreator 2018-08-06T14:22:36
#
#-------------------------------------------------

QT       += core gui
QT       += quick
QT       += widgets
QT += quickwidgets
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oneide
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    mycolor.cpp \
    mywidget.cpp \
    qmlqgraphcisview.cpp \
    widgeteventd.cpp \
    qquickgraphicsview.cpp \
    programtool.cpp \
    qquickgraphicsscene.cpp

HEADERS += \
        mainwindow.h \
    mycolor.h \
    mywidget.h \
    qmlqgraphcisview.h \
    widgeteventd.h \
    qquickgraphicsview.h \
    programtool.h \
    qquickgraphicsscene.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    qmlqrc.qrc \
    qssqrc.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
