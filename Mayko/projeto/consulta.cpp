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
