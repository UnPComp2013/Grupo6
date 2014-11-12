#ifndef TURMA_H
#define TURMA_H

#include <iostream>
#include <string>
#include <disciplina.h>
#include <professor.h>
#include <matrix.h>

class Turma : public Professor, public Disciplina
{
    std::string nome;
    int QuantidadeDeDisciplinas, QuantidadeDeProfessores;

    Disciplina *Disciplinas;
    Professor *Professores;
    Matrix<char> QuadroDeHorarioTurma;

public:
    Turma();
    Turma(std::string nome);

    int GetQuantidadeDeDisciplinas(){ return this->QuantidadeDeDisciplinas; }
    int GetQuantidadeDeProfessores(){ return this->QuantidadeDeProfessores; }

    //Só poderá ser setado valores pelo banco ou pela interface do programa através do construtor
    //void setQuantidadeDisciplinas(unsigned QuantidadeDeDisciplinas);
    //void setQuantidadeProfessores(unsigned QuantidadeDeProfessores);
};

#endif // TURMA_H
