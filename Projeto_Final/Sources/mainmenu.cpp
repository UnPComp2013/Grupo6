#include "mainmenu.h"
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
    delete pso;
    delete Av;
    delete turma;
    delete ui;
}

void MainMenu::organizarQuadro()
{
    QTableWidgetItem curItem;
    QString NomeDoProfessor;
    Matrix<double> X;

    this->Av = new avalia(ui->turmas->currentText().toStdString());
    this->pso = new PSO<double>(1, 50, 50, 1011, 10, 1010, false);

    X = this->pso->RunA(*this->Av);
    curItem.setText(QString("%1").arg(X.getMat(0,0)));

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6; j++){
            //NomeDoProfessor = (Av->QuadroDeHorario[i][j].getProfessor().GetNome()).c_str();
            //curItem.setText(QString((Av->QuadroDeHorario[i][j].getNome()).c_str()) +"\n"+ NomeDoProfessor);
            //curItem.setText(QString((Av->QuadroDeHorario[i][j].getNome()).c_str()));
            //curItem.setText(QString("%1").arg(X.getMat(0,0)));
            ui->QuadroDeHorario->setItem(i,j, curItem.clone());
        }
    }
}

void MainMenu::ativar1()
{
    MainMenu::show();
}
