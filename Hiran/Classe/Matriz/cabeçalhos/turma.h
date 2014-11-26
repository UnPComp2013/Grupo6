#ifndef TURMA_H
#define TURMA_H

#include <iostream>
#include <string>
#include <Headers/disciplina.h>
#include <Headers/professor.h>
#include <Headers/primitiveLibs\matrix.h>

class Turma : public Professor, public Disciplina
{
    std::string nome;
    int QuantidadeDeDisciplinas, QuantidadeDeProfessores;

public:
    Turma();
    Turma(std::string nome);
    ~Turma();
    int GetQuantidadeDeDisciplinas(){ return this->QuantidadeDeDisciplinas; }
    int GetQuantidadeDeProfessores(){ return this->QuantidadeDeProfessores; }

    Disciplina *Disciplinas;
    Professor *Professores;
    Matrix<char> QuadroDeHorarioTurma;
    //Só poderá ser setado valores pelo banco ou pela interface do programa através do construtor
    //void setQuantidadeDisciplinas(unsigned QuantidadeDeDisciplinas);
    //void setQuantidadeProfessores(unsigned QuantidadeDeProfessores);
};

#endif // TURMA_H
