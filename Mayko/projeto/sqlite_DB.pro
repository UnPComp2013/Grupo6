#-------------------------------------------------
#
# Project created by QtCreator 2014-09-09T12:55:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqlite_DB
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    cadastro.cpp \
    consulta.cpp \
    menu.cpp \
    matrix.cpp \
    professor.cpp

HEADERS  += login.h \
    cadastro.h \
    consulta.h \
    menu.h \
    matrix.h \
    professor.h

FORMS    += login.ui \
    cadastro.ui \
    consulta.ui \
    menu.ui
