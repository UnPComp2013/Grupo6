#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cadastrar_clicked()
{
 cadastro Cadastro;
 MainWindow w;

 Cadastro.setModal(true);
// hide(w);
 Cadastro.exec();
}
