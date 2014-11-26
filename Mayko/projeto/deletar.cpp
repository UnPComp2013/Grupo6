#include "deletar.h"
#include "ui_deletar.h"

Deletar::Deletar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletar)
{
    ui->setupUi(this);
}

Deletar::~Deletar()
{
    delete ui;
}
