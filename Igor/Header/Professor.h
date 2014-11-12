#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <matrix.h>
#include <string>

//template <class TipoDaClasse>
class Professor
{
    unsigned ID, QuantidadeDisciplinas;     //Informações do professor
    std::string nome, Disciplinas[];
    Matrix<bool> QuadroHorario, restricoes;       //Matriz de restrição e horário
    //Disciplina disciplinas[];

public:
    Professor();
    Professor(unsigned ID);                 //Puxa do banco as infos do professor
    ~Professor();

    std::string *GetDisciplinas();               //Retorna as disciplinas que o professor leciona
    Matrix<bool> GetQuadroHorario();            //Retorna o Quadro de Horário atual
    Matrix<bool> GetRestricao();                //Retorna as restricoes de horario

    void SetQuadroHorario(Matrix<bool> A);      //Salva o Quadro de Horário (organizado pelo PSO)
};

#endif // PROFESSOR_H
