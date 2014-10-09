#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    
    this->CriaAcao();
    this->CriaMenu();
    
    statusBar()->showMessage(tr("!!!Bom dia!!!"));
    statusBar()->setSizeGripEnabled(false);
    
    ui->pushButton->setText("Confirma");
    ui->label_3->setText("Senha");
    ui->label_2->setText("Login");
  
      if(!connOpen())
          ui->label->setText("Falha ao abrir a database");
  
      else
          ui->label->setText("conectado...");
}

Login::~Login()
{
    delete ui;
    delete AcaoSair;
    delete MenuArquivo;
}
void Login::on_btn_ok_clicked()
{
    QString login, senha;
    login=ui->ln_login->text();
    senha=ui->ln_senha->text();

    if(!connOpen())
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
