QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Tabladedispersion.cpp \
    busqueda_en_memoria.cpp \
    cifrar_window.cpp \
    controlador_bin.cpp \
    hashing_window.cpp \
    listamemoria.cpp \
    main.cpp \
    mainwindow.cpp \
    model_email.cpp

HEADERS += \
    AVL.h \
    AVL2.h \
    AVL_Paginado.h \
    ListaSimplementeLigada.h \
    Tabladedispersion.h \
    busqueda_en_memoria.h \
    cifrar_window.h \
    controlador_bin.h \
    hashing_window.h \
    listamemoria.h \
    mainwindow.h \
    model_email.h

FORMS += \
    busqueda_en_memoria.ui \
    cifrar_window.ui \
    hashing_window.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = Graphicloads-100-Flat-2-Email.ico

