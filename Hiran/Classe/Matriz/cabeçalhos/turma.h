#ifndef TURMA_H
#define TURMA_H
#include <matrix.h>
#include <iostream>
#include <string>
#include <disciplina.h>
#include <professor.h>

class Turma
{
    std::string nome;
    int QuantidadeDeDisciplinas, QuantidadeDeProfessores;

    Disciplina *Disciplinas;
    Professor *Professores;
    Matrix<char> QuadroDeHorarioTurma;
public:
    Turma();
    Turma(std::string nome);

    int GetQuantidadeDeDisciplinas(){return this->QuantidadeDeDisciplinas;}
    int GetQuantidadeDeProfessores(){return this->QuandtidadeDeProfessores;}
};

#endif // TURMA_H
