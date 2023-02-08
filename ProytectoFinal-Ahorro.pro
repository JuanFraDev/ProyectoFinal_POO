QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controlador.cpp \
    edit_users.cpp \
    iniciodesesion.cpp \
    main.cpp \
    movimientos.cpp \
    nuevo_egre.cpp \
    nuevo_ing.cpp \
    pagprincipal.cpp \
    register.cpp

HEADERS += \
    controlador.h \
    edit_users.h \
    iniciodesesion.h \
    movimientos.h \
    nuevo_egre.h \
    nuevo_ing.h \
    pagprincipal.h \
    register.h

FORMS += \
    edit_users.ui \
    iniciodesesion.ui \
    movimientos.ui \
    nuevo_egre.ui \
    nuevo_ing.ui \
    pagprincipal.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

DISTFILES +=
