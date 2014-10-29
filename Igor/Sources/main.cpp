#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();

    return a.exec();
}

#include <QCoreApplication>
#include <Matrix.h>

/*
    Matrix<double> A, B;

    A.add(0,0, 1);
    A.add(1,0, 1);
    A.add(0,1, 1);
    A.add(1,1, 1);

    B.add(0,0, 1);
    B.add(1,0, 1);
    B.add(0,1, 1);
    B.add(1,1, 1);

    A.print();
    B.print();
    (A*B).print();

    return a.exec();
}
*/
