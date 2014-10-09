#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
  
      if(!connOpen())
          ui->label->setText("Falha ao abrir a database");
  
      else
          ui->label->setText("conectado...");
}

Login::~Login()
{
    delete ui;
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

  

}
