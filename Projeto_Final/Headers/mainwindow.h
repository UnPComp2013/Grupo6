#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mainmenu.h>
#include <QMainWindow>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MainMenu mainMenu;

public slots:
    void ConfirmarLogin();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool ativarMenu1;
    Ui::MainWindow *ui;
    MainMenu *Menu1;
};

#endif // MAINWINDOW_H
