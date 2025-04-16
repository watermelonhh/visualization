#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QT += widgets uitools

QT += core gui widgets uitools printsupport  # 确保 widgets 和 uitools 都在
CONFIG += c++11
LIBS += -lws2_32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autoue.cpp \
    filewindow.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    networkwindow.cpp \
    qcustomplot.cpp \
    serialwindow.cpp

HEADERS += \
    autoue.h \
    basedefine.h \
    filewindow.h \
    global.h \
    mainwindow.h \
    networkwindow.h \
    qcustomplot.h \
    serialwindow.h

FORMS += \
    mainwindow.ui \
    NetworkWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
