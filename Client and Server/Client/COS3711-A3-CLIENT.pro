QT       += core gui
QT       += network
QT       += concurrent
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    box.cpp \
    calculations.cpp \
    caretaker.cpp \
    clienttcp.cpp \
    container.cpp \
    containerfactory.cpp \
    containerlist.cpp \
    cylinder.cpp \
    main.cpp \
    mainclient.cpp \
    mainwidget.cpp \
    momento.cpp \
    pallet.cpp \
    palletlist.cpp \
    popupview.cpp \
    serialcode.cpp \
    validator.cpp \
    writexml.cpp

HEADERS += \
    box.h \
    calculations.h \
    caretaker.h \
    clienttcp.h \
    container.h \
    containerfactory.h \
    containerlist.h \
    cylinder.h \
    mainclient.h \
    mainwidget.h \
    momento.h \
    pallet.h \
    palletlist.h \
    popupview.h \
    serialcode.h \
    validator.h \
    writexml.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

DISTFILES +=
