#include "Headers/mainmenu.h"
#include "ui_mainmenu.h"
#include <iostream>

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    connect(ui->organizar, SIGNAL(clicked()), this, SLOT(organizarQuadro()));
    connect(ui->actionHorarios, SIGNAL(triggered()), this, SLOT(ativar1()));
}

MainMenu::~MainMenu()
{
    //delete turma;
    delete ui;
}
//funação que organiza o quadro de horarios com as disciplinas
void MainMenu::organizarQuadro()
{
    QTableWidgetItem curItem;
    //QString NomeDoProfessor;

    this->Av = new avalia(ui->turmas->currentText().toStdString());

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            //NomeDoProfessor = (Av->QuadroDeHorario[i][j].getProfessor().GetNome()).c_str();
            //curItem.setText(QString((Av->QuadroDeHorario[i][j].getNome()).c_str()) +"\n"+ NomeDoProfessor);
            curItem.setText(QString((Av->QuadroDeHorario[i][j].getNome()).c_str()));
            ui->QuadroDeHorario->setItem(i,j, curItem.clone());
        }
    }
}

void MainMenu::ativar1()
{
    MainMenu::show();
}
