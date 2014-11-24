#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Entrar, SIGNAL(clicked()), this, SLOT(ConfirmarLogin()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Menu1;
}

void MainWindow::ConfirmarLogin()
{
    MainWindow::hide();
    mainMenu.show();
}
