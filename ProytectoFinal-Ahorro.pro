QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    categorias.cpp \
    controlador.cpp \
    edit_users.cpp \
    iniciodesesion.cpp \
    main.cpp \
    movegreso.cpp \
    movingreso.cpp \
    nueva_cate.cpp \
    nuevo_egre.cpp \
    nuevo_ing.cpp \
    nuevoedituser.cpp \
    pagprincipal.cpp \
    register.cpp \
    reporte.cpp

HEADERS += \
    categorias.h \
    controlador.h \
    edit_users.h \
    iniciodesesion.h \
    movegreso.h \
    movingreso.h \
    nueva_cate.h \
    nuevo_egre.h \
    nuevo_ing.h \
    nuevoedituser.h \
    pagprincipal.h \
    register.h \
    reporte.h

FORMS += \
    categorias.ui \
    edit_users.ui \
    iniciodesesion.ui \
    movegreso.ui \
    movingreso.ui \
    nueva_cate.ui \
    nuevo_egre.ui \
    nuevo_ing.ui \
    nuevoedituser.ui \
    pagprincipal.ui \
    register.ui \
    reporte.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc

DISTFILES +=
