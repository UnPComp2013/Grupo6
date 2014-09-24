#include "menu.h"
#include "ui_menu.h"
#include "cadastro.h"
#include "consulta.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}


void menu::on_btn_cadastrar_clicked()
{
    menu m;

    m.hide();
    Cadastro = new cadastro(this);
    Cadastro->show();
}

void menu::on_btn_consultar_clicked()
{
   menu m;
   m.close();
   Consulta = new consulta(this);
   Consulta->show();
}
