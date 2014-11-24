#include "mainwindow.h"
#include <QApplication>
#include <disciplina.h>
#include <professor.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w2;
    w2.show();

    return a.exec();
}
