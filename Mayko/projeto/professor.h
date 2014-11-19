#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <matrix.h>

class Professor
{

   Matrix HorarioP, Restricao;

public:

    Professor();
    ~Professor();
    Matrix CadastroHorarioP(bool A);
    Matrix CadastroRestricao(bool A);
    bool HaRestricao(Matrix A);
    Matrix PosicaoRestricao(unsigned rows, unsigned cols);
    Matrix TabelaHorario();


};

#endif // PROFESSOR_H
