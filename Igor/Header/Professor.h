#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <matrix.h>
#include <string>

template <class TipoDaClasse>
class Professor
{
    unsigned ID, QuantidadeDisciplinas;     //Informações do professor
    std::string nome;
    Matrix<TipoDaClasse> QuadroHorario, restricoes;       //Matriz de restrição e horário
    //Disciplina disciplinas[];
public:
    Professor(unsigned ID);                 //Puxa do banco as infos do professor
    ~Professor();

    Matrix<TipoDaClasse> GetQuadroHorario();              //Retorna o Quadro de Horário atual
    Matrix<TipoDaClasse> GetRestricao();                  //Retorna as restricoes de horario

    void SetQuadroHorario(Matrix<TipoDaClasse> A);        //Salva o Quadro de Horário (organizado pelo PSO)
    //Disciplina
};

#endif // PROFESSOR_H
