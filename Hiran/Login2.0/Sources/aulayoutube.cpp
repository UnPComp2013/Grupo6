#include "aulayoutube.h"
#include "ui_aulayoutube.h"


AulaYouTube::AulaYouTube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AulaYouTube)
{  
    ui->setupUi(this);

    this->CriaAcao();
    this->CriaMenu();

    statusBar()->showMessage(tr("!!!Bom dia!!!"));
    statusBar()->setSizeGripEnabled(false);

    ui->pushButton->setText("Confirma");
    ui->label->setText("Senha");
    ui->label_2->setText("Login");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Confirma()));
}

AulaYouTube::~AulaYouTube()
{
    delete ui;
    delete AcaoSair;
    delete MenuArquivo;
}

void AulaYouTube::CriaAcao()
{
    AcaoSair = new QAction(QString("&Sair"), this);
    AcaoSair->setShortcut(QString("CTRL+S"));
    AcaoSair->setStatusTip(QString("Encerra login."));
    connect(AcaoSair,SIGNAL(triggered()), this, SLOT(Sair()));

}
void AulaYouTube::CriaMenu()
{
    MenuArquivo= menuBar()->addMenu( QString("&Arquivo"));
    MenuArquivo->addAction(AcaoSair);

}

void AulaYouTube::Sair()
{
    close();

}

void AulaYouTube::Confirma()
{

}

