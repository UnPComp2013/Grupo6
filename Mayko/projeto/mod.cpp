#include "mod.h"
#include "ui_mod.h"
#include "login.h"
#include <QMessageBox>

mod::mod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mod)
{
    ui->setupUi(this);
}

mod::~mod()
{
    delete ui;
}

void mod::on__1_clicked()
{
    Login conn;
    QString curso, email, nome;
    curso = ui->ln_curso_1->text();
    email = ui->ln_email_1->text();
    nome = ui->ln_nome_1->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Update TBL_projeto set nome='"+nome+"', curso ='"+curso+"',email='"+email+"',' where nome='"+nome+"'");

    if(qry.exec())
    {
      QMessageBox::information(this, tr("Editar"), tr("atualizado com sucesso"));
      conn.connClose();
      this->hide();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
