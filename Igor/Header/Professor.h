#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <matrix.h>
#include <string>

class Professor
{
    unsigned ID, QuantidadeDisciplinas;     //Informações do professor
    string nome;
    Matrix QuadroHorario, restricoes;       //Matriz de restrição e horário
    //Disciplina disciplinas[];
public:
    Professor(unsigned ID);                 //Puxa do banco as infos do professor
    ~Professor();

    Matrix GetQuadroHorario();              //Retorna o Quadro de Horário atual
    Matrix GetRestricao();                  //Retorna as restricoes de horario

    void SetQuadroHorario(Matrix A);        //Salva o Quadro de Horário (organizado pelo PSO)
    //Disciplina
};

#endif // PROFESSOR_H
