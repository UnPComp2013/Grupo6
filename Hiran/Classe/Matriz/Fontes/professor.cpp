#include "Headers/professor.h"

Professor::Professor()
{
    //Construtor de inicialiação, valores em branco.
    this->ID = 0;
    this->nome = "";
    this->QuadroHorario.init(0,0);
    this->restricoes.init(0,0);
    this->QuantidadeDisciplinas = 1;
}

Professor::Professor(unsigned ID)
{
    //Fará uma busca no banco através do ID recebido.
    //Valores Temporarios.
    this->ID = ID;
    this->nome = "Eustáquio";
    this->QuadroHorario.init(0,0);
    this->restricoes.init(0,0);
    this->QuantidadeDisciplinas = 0;
}

Professor::~Professor()
{
    delete Disciplinas;
}

//---------------------GETERS & SETERS----------------------//
//---------------------Início dos GETS----------------------//
//Pega o vetor de disciplinas
std::string Professor::GetDisciplina(int Index)
{
    return this->Disciplinas[Index];
}
//Pega o quadro de horarios
Matrix<bool> Professor::GetQuadroHorario()
{
    return this->QuadroHorario;
}
//Pega as restrições do professor
Matrix<bool> Professor::GetRestricao()
{
    return this->restricoes;
}
//Pega o nome do professor
std::string Professor::GetNome()
{
    return this->nome;
}

//-----------------------Fim dos GETS-----------------------//
//---------------------Início dos SETS----------------------//
//Atribui uma matriz(bool) a quadro de horario
void Professor::SetQuadroHorario(Matrix<bool> A)
{
    this->QuadroHorario = A;
}
//Entra com o nome do professor
void Professor::SetNome(string nome)
{
    this->nome = nome;
}
//Atribui as disciplinas que o professor leciona
void Professor::SetDisciplina(string disciplina)
{
    this->Disciplinas = (std::string*)new std::string[1];
    this->Disciplinas[0] = disciplina;
    this->QuantidadeDisciplinas = 1;
}
//Atribui as disciplinas que o professor leciona caso o professor lecione 2 materias
void Professor::SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2)
{
    if(QntDeDisciplinas > 2)
        QntDeDisciplinas = 2;

    this->Disciplinas = (std::string*)new std::string[QntDeDisciplinas];
    this->Disciplinas[0] = Disciplina1;
    this->Disciplinas[1] = Disciplina2;
    this->QuantidadeDisciplinas = QntDeDisciplinas;
}
//Atribui as disciplinas que o professor leciona caso o professor lecione 3 materias
void Professor::SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3)
{
    if(QntDeDisciplinas > 3)
        QntDeDisciplinas = 3;

    this->Disciplinas = (std::string*)new std::string[QntDeDisciplinas];
    this->Disciplinas[0] = Disciplina1;
    this->Disciplinas[1] = Disciplina2;
    this->Disciplinas[2] = Disciplina3;
    this->QuantidadeDisciplinas = QntDeDisciplinas;
}
//Atribui as disciplinas que o professor leciona caso o professor lecione 4 materias
void Professor::SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3, std::string Disciplina4)
{
    if(QntDeDisciplinas > 4)
        QntDeDisciplinas = 4;

    this->Disciplinas = (std::string*)new std::string[QntDeDisciplinas];
    this->Disciplinas[0] = Disciplina1;
    this->Disciplinas[1] = Disciplina2;
    this->Disciplinas[2] = Disciplina3;
    this->Disciplinas[3] = Disciplina4;
    this->QuantidadeDisciplinas = QntDeDisciplinas;
}
//-------------------------Fim dos--------------------------//
//---------------------GETERS & SETERS----------------------//
