#include "Headers/disciplina.h"

Disciplina::Disciplina()
{
}

//---------------------GETERS & SETERS----------------------//
//---------------------Início dos GETS----------------------//
//pega o nome da disciplina
std::string Disciplina::getNome()
{
    return this->nome;
}
//Pega a carga horaria da disciplina
int Disciplina::getCargaHoraria()
{
   return this->cargaHoraria;
}
//pega o valor da disciplina se ela vai ser pratica(TRUE) ou não
bool Disciplina::getPraticaOuNao()
{
    return this->aulaPratica;
}
//Pega o professor que vai lecionar a disciplina
Professor Disciplina::getProfessor()
{
    return this->professor;
}

//-----------------------Fim dos GETS-----------------------//
//---------------------Início dos SETS----------------------//

//Declarando o valor da carga horaria da disciplina
void Disciplina::setCargaHoraria(int CH)
{
    this->cargaHoraria = CH;
}
//atribuindo o nome da disciplina
void Disciplina::setNome(std::string nome)
{
    this->nome = nome;
}
//declarando o professor que vai da a aula
void Disciplina::setProfessor(Professor professor)
{
    this->professor = professor;
}
//-------------------------Fim dos--------------------------//
//---------------------GETERS & SETERS----------------------//

