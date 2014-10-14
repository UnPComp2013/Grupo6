#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);

    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/DIEGO/Desktop/douglas/db/database.db");

    if(!mydb.open())
       ui->label->setText("Falha ao abrir a database");

    else
       ui->label->setText("conectado....");

}

void Login::on_btn_ok_clicked()
{
    QString login, senha;
    login=ui->ln_login->text();
    senha=ui->ln_senha->text();

    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;

    if(qry.exec("SELECT *  FROM TBL_projeto WHERE Login='"+login +"'AND Senha='"+senha +"'"))
    {
        int count;
        while (qry.next())
        {
            count++;
        }
        if(count==1)
            ui->label->setText("login e senha estão corretas");
        if(count>1)
            ui->label->setText("dupilicate login e senha");
        if(count<1)
            ui->label->setText("login e senha não estão corretas");

    }
}
Login::~Login()
{
    delete ui;
}
