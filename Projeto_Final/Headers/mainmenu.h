#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <turma.h>
#include <avalia.h>

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT
    Turma *turma;
    avalia *Av;

public slots:
    void ativar1();

private slots:
    void organizarQuadro();

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private:
    Ui::MainMenu *ui;

};

#endif // MAINMENU_H
