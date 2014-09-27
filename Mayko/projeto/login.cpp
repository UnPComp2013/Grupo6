#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/DIEGO/Pictures/lp_logo_unp.png");
    ui->label_pic->setPixmap(pix);

    mydb= QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/DIEGO/Desktop/douglas/db/database.db");

    if(!mydb.open())
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

    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }
    QSqlQuery qry;

    if(qry.exec("SELECT *  FROM TBL_projeto WHERE Login='"+login +"'AND Senha='"+senha +"'"))
    {
        int count=0;
        while (qry.next())
        {
            count++;
        }
        if(count==1)
        {

        }
        if(count>1)
            ui->label->setText("duplicate login e senha");
        if(count<1)
            ui->label->setText("login e senha não estão corretas");

    }
}
