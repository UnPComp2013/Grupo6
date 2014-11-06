#include "professor.h"

Professor::Professor ()
{
  this->HorarioProfessor  = NULL;
  this->Restricoes        = NULL;
  this->Disciplinas       = NULL;
}

Professor::~Professor ()
{
  delete this->HorarioProfessor;
  delete this->Restricoes;
  delete this->Disciplinas;
}
