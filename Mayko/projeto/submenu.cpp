#include "submenu.h"
#include "ui_submenu.h"

submenu::submenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::submenu)
{
    ui->setupUi(this);
}

submenu::~submenu()
{
    delete ui;
}
