QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    availabilityinterface.cpp \
    booking.cpp \
    bookinginterface.cpp \
    checkoutinterface.cpp \
    hotel.cpp \
    main.cpp \
    mainwindow.cpp \
    transactioninterface.cpp

HEADERS += \
    availabilityinterface.h \
    booking.h \
    bookinginterface.h \
    checkoutinterface.h \
    hotel.h \
    mainwindow.h \
    transactioninterface.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
