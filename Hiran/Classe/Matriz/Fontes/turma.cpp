#include "turma.h"

Turma::Turma()
{
    this->nome = "";
    this->QuantidadeDeDisciplinas = 0;
    this->QuandtidadeDeProfessores = 0;
    this->QuadroDeHorarioTurma = 0;

    this->Disciplinas = new Disciplina[QuantidadeDeDisciplinas];
    this->Professores = new Professor[QuantidadeDeProfessores];

}
Turma::Turma(std::string nome)
{
    this->nome = nome;
    this->QuantidadeDeDisciplinas = 0;
    this->QuantidadeDeProfessores = 0;
    this-> QuadroDeHorarioTurma = 0;

    this->Disciplinas = new Disciplina[QuantidadeDeDisciplinas];
    this->Professores = new Professor[QuantidadeDeProfessores];
}

