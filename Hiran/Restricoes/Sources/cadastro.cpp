#include "cadastro.h"
#include "ui_cadastro.h"

Cadastro::Cadastro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);

    this->criaAcao();
    this->criaMenu();

    statusBar()->showMessage(tr("Cadastro Restrições."));
    statusBar()->setSizeGripEnabled(false);

    connect(ui->btn_confirma, SIGNAL(clicked()),this, SLOT(confirma()));
    connect(ui->btn_cancelar, SIGNAL(clicked()),this, SLOT(cancelar()));
}
