#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "consulta.h"
#include "cadastro.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_cadastrar_clicked();

    void on_btn_consultar_clicked();

private:
    Ui::MainWindow *ui;
    consulta *Consulta;
    cadastro *Cadastro;
};

#endif // MAINWINDOW_H
