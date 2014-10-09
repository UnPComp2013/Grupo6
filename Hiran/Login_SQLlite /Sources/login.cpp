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
