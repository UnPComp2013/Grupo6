#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cadastro.h"
#include "consulta.h"


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

 MainWindow w;


w.close();
 Cadastro = new cadastro(this);
 Cadastro->show();
}


void MainWindow::on_btn_consultar_clicked()
{
Consulta = new consulta(this);
Consulta->show();
}
