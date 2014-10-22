#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mainmenu.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void ConfirmarLogin();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    bool AtivarMenu1 = false;
    Ui::MainWindow *ui;
    MainMenu *Menu1;
};

#endif // MAINWINDOW_H
