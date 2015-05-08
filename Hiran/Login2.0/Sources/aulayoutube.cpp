#include "aulayoutube.h"
#include "ui_aulayoutube.h"


AulaYouTube::AulaYouTube(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AulaYouTube)
{  
    ui->setupUi(this);

    this->CriaAcao();
    this->CriaMenu();
    
    //Barra de status.
    statusBar()->showMessage(tr("!!!Bom dia!!!"));
    statusBar()->setSizeGripEnabled(false);
    
    //nomeando os componentes.
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
//função que cria um sub-arquivo dentro da barra de menu.
void AulaYouTube::CriaAcao()
{
    AcaoSair = new QAction(QString("&Sair"), this);
    AcaoSair->setShortcut(QString("CTRL+S"));
    AcaoSair->setStatusTip(QString("Encerra login."));
    connect(AcaoSair,SIGNAL(triggered()), this, SLOT(Sair()));

}
//função que cria a barra de menu Arquivo
void AulaYouTube::CriaMenu()
{
    MenuArquivo= menuBar()->addMenu( QString("&Arquivo"));
    MenuArquivo->addAction(AcaoSair);

}
//função que implementa a saida se pelo menu barra
void AulaYouTube::Sair()
{
    close();

}

void AulaYouTube::Confirma()
{
    QString login, senha;
    login=ui->ln_login->text();
    senha=ui->ln_senha->text();

    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT *  FROM TBL_projeto WHERE Login='"+login +"'AND Senha='"+senha +"'");

    if(qry.exec())
    {
        int count=0;
        while (qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label->setText("login e senha estão corretas");
            connClose();
            this->hide();
            menu Menu;
            Menu.setModal(true);
            Menu.exec();
        }
        if(count>1)
            ui->label->setText("duplicate login e senha");
        if(count<1)
            ui->label->setText("login e senha não estão corretas");

    }
}

