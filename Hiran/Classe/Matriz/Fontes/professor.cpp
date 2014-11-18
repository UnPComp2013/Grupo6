#include "professor.h"

Professor::Professor()
{
    this->ID = ID;
    this->nome = "Esutáquio";
    this->QuadroHorario = 0;
    this->restricoes = NULL;
    this->QuantidadeDisciplinas = 0;
}
Professor::Professor(unsigned ID)
{
    this->ID = ID;
    this->nome = "Esutáquio";
    this->QuadroHorario = 0;
    this->restricoes = NULL;
    this->QuantidadeDisciplinas = 0;
}
Professor::~Professor()
{
}
std::string* Professor::GetDiscliplinas()
{
    return this->Disciplinas;
}
