#include "consulta.h"
#include "ui_consulta.h"

consulta::consulta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consulta)
{
    ui->setupUi(this);
}

consulta::~consulta()
{
    delete ui;
}

void consulta::on_btn_update_clicked()
{
    Login conn;/*
    QString curso, email, nome, senha, usuario;
    curso = ui->ln_curso->text();
    email = ui->ln_email->text();
    nome = ui->ln_nome->text();
    usuario = ui->ln_usuario->text();
    senha = ui->ln_senha->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Update TBL_projeto set nome='"+nome+"', curso ='"+curso+"',email='"+email+"',usuario= '"+usuario+"', senha='"+senha+"' where nome='"+nome+"'");

    if(qry.exec())
    {
      QMessageBox::information(this, tr("Editar"), tr("atualizado com sucesso"));
      conn.connClose();
      this->hide();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }*/


}

void consulta::on_btn_atabela_clicked()
{
    Login conn;
    QSqlQueryModel *Modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);

    qry->prepare("select * from TBL_projeto");

    qry->exec();
    Modal->setQuery(*qry);
    ui->tbl_coordenadores->setModel(Modal);

    conn.connClose();
    qDebug() <<(Modal->rowCount());
}

void consulta::on_btn_Cadastro_clicked()
{

}
