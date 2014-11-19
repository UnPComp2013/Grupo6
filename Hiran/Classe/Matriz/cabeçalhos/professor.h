#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <matrix.h>
#include <iostream>
#include <string>

class Professor
{
    unsigned ID, QuantidadeDisciplinas;
    std::string nome, Disciplinas[];
    Matrix<bool> QuadroHorario, restricoes;

public:

    Professor();
    Professor(unsigned ID);
    ~Professor();

    std::string *GetDiscliplinas();
    Matrix<bool> GetQuadroHorarios();
    Matrix<bool> GetRestricao();

    void SetQuadroHorario(Matrix<bool> A);

};

#endif // PROFESSOR_H
