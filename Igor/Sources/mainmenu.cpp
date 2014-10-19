#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->actionHorarios, SIGNAL(triggered()), this, SLOT(ativar1()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::ativar1()
{
   //
}
