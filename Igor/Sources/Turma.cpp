#include "turma.h"

Turma::Turma()
{
    this->nome = "";
    this->QuantidadeDeDisciplinas = 0;
    this->QuantidadeDeProfessores = 0;
    this->QuadroDeHorarioTurma = 0;

    this->Disciplinas = new Disciplina[QuantidadeDeDisciplinas];
    this->Professores = new Professor[QuantidadeDeProfessores];
}

Turma::Turma(std::string nome)
{
    //Faz a pesquisa no pelo nome da disciplina e retorna os valores
    this->nome = nome;
    this->QuantidadeDeDisciplinas = 0;      //Valor Fictício
    this->QuantidadeDeProfessores = 0;      //Valor Fictício
    this->QuadroDeHorarioTurma = 0;         //Valor Fictício

    this->Disciplinas = new Disciplina[QuantidadeDeDisciplinas];
    this->Professores = new Professor[QuantidadeDeProfessores];
}
