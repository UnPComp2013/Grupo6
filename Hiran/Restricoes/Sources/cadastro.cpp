#include "cadastro.h"
#include "ui_cadastro.h"

Cadastro::Cadastro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);

    this->criaAcao();
    this->criaMenu();

    statusBar()->showMessage(tr("Cadastro Restrições."));
    statusBar()->setSizeGripEnabled(false);

    connect(ui->btn_confirma, SIGNAL(clicked()),this, SLOT(confirma()));
    connect(ui->btn_cancelar, SIGNAL(clicked()),this, SLOT(cancelar()));
}
Cadastro::~Cadastro()
{
    delete acaoSair;
    delete menuArquivo;
    delete ui;
}

void Cadastro::criaAcao()
{
    acaoSair = new QAction(QString("&Sair"), this);
    acaoSair->setShortcut(QString("CTRL+S"));
    acaoSair->setStatusTip(QString("Encerra Cadastro."));
    connect(acaoSair, SIGNAL(triggered()), this, SLOT(implementaAcaoSair()));

}

void Cadastro::criaMenu()
{
    menuArquivo = menuBar()->addMenu(QString("&Arquivo"));
    menuArquivo->addAction(acaoSair);
}

void Cadastro::implementaAcaoSair()
{
    close();
}

void Cadastro::cancelar()
{
    close();
}

void Cadastro::confirma()
{
}
