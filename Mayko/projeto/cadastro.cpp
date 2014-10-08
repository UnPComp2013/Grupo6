#include "cadastro.h"
#include "ui_cadastro.h"



cadastro::cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro)
{
    ui->setupUi(this);
    Login conn;
        if(!conn.connOpen())
        {
            ui->lb_sec_status->setText("Falha ao abrir a database");
        }

        else
        {
            ui->lb_sec_status->setText("conectado...");
        }
}

cadastro::~cadastro()
{
    delete ui;
}




void cadastro::on_btn_confirma_clicked()
{
    Login conn;
    QString curso, email, nome, senha, usuario;
    curso = ui->ln_curso->text();
    email = ui->ln_email->text();
    nome = ui->ln_nome->text();
    usuario = ui->ln_usuario->text();

    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into TBL_projeto (curso, email, nome, senha, Login) values ('"+curso+"','"+email+"','"+nome+"','"+senha+"','"+usuario+"')");

    if(qry.exec())
    {
      QMessageBox::critical(this, tr("Salvando"), tr("Salvo com sucesso"));
      conn.connClose();
    }
    else
    {
        QMessageBox::critical(this,tr("Error::"),qry.lastError().text());
    }
}
