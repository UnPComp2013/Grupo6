#-------------------------------------------------
#
# Project created by QtCreator 2014-09-03T11:48:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SOQH
TEMPLATE = app


SOURCES += main.cpp\
        mainmenu.cpp \
    mainwindow.cpp \
    professor.cpp \
    turma.cpp \
    disciplina.cpp \
    optimizationLibs/pid.cpp \
    optimizationLibs/pso.cpp \
    primitiveLibs/matrix.cpp \
    simulationLibs/lsim.cpp \
    avalia.cpp

HEADERS  += mainmenu.h \
    mainwindow.h \
    matrix.h \
    professor.h \
    turma.h \
    disciplina.h \
    optimizationLibs/pid.h \
    optimizationLibs/pso.h \
    primitiveLibs/matrix.h \
    simulationLibs/lsim.h \
    avalia.h

FORMS    += mainmenu.ui \
    mainwindow.ui
