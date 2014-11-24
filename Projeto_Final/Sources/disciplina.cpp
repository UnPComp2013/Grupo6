#include "disciplina.h"

Disciplina::Disciplina()
{
}

//---------------------GETERS & SETERS----------------------//
//---------------------Início dos GETS----------------------//
std::string Disciplina::getNome()
{
    return this->nome;
}

int Disciplina::getCargaHoraria()
{
   return this->cargaHoraria;
}

bool Disciplina::getPraticaOuNao()
{
    return this->aulaPratica;
}

Professor Disciplina::getProfessor()
{
    return this->professor;
}

//-----------------------Fim dos GETS-----------------------//
//---------------------Início dos SETS----------------------//


void Disciplina::setCargaHoraria(int CH)
{
    this->cargaHoraria = CH;
}
void Disciplina::setNome(std::string nome)
{
    this->nome = nome;
}

void Disciplina::setProfessor(Professor professor)
{
    this->professor = professor;
}
//-------------------------Fim dos--------------------------//
//---------------------GETERS & SETERS----------------------//
