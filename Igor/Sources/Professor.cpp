#include "professor.h"

Professor::Professor()
{
    //Construtor de inicialiação, valores em branco.
    this->ID = ID;
    this->nome = "Esutáquio";
    this->QuadroHorario = 0;
    this->restricoes = NULL;
    this->QuantidadeDisciplinas = 0;
}

Professor::Professor(unsigned ID)
{
    //Fará uma busca no banco através do ID recebido.
    //Valores Temporarios.
    this->ID = ID;
    this->nome = "Esutáquio";
    this->QuadroHorario = 0;
    this->restricoes = NULL;
    this->QuantidadeDisciplinas = 0;
}

Professor::~Professor()
{

}

std::string* Professor::GetDisciplinas()
{
    return this->Disciplinas;
}

Matrix<bool> Professor::GetQuadroHorario()
{
    return this->QuadroHorario;
}

Matrix<bool> Professor::GetRestricao()
{
    return this->restricoes;
}

void Professor::SetQuadroHorario(Matrix<bool> A)
{
    this->QuadroHorario = A;
}
