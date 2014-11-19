#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>
#include <matrix.h>

class Disciplina
{
    
    std::string nome;
    unsigned CargaHoraria;
    Matrix<bool> QuadroHorario;
    //Professor professores;

public:
    Disciplina();
    //~Disciplina();
};

#endif // DISCIPLINA_H
