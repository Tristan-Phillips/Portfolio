QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    booking.cpp \
    bookroomdialog.cpp \
    checkoutdialog.cpp \
    hotel.cpp \
    main.cpp \
    mainwindow.cpp \
    roomavailabledialog.cpp \
    transactiondialog.cpp

HEADERS += \
    booking.h \
    bookroomdialog.h \
    checkoutdialog.h \
    hotel.h \
    mainwindow.h \
    roomavailabledialog.h \
    transactiondialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
