#-------------------------------------------------
#
# Project created by QtCreator 2014-08-31T17:35:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projeto
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cadastro.cpp \
    consulta.cpp

HEADERS  += mainwindow.h \
    cadastro.h \
    consulta.h

FORMS    += mainwindow.ui \
    cadastro.ui \
    consulta.ui
