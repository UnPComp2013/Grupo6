#include "aulayoutube.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AulaYouTube w;
    w.show();

    return a.exec();
}
