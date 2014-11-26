#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <Headers/primitiveLibs\matrix.h>
#include <string>

//template <class TipoDaClasse>
class Professor
{
    unsigned ID, QuantidadeDisciplinas;     //Informações do professor
    std::string nome, *Disciplinas;
    Matrix<bool> QuadroHorario, restricoes;       //Matriz de restrição e horário
    //Disciplina disciplinas[];

public:
    Professor();
    Professor(unsigned ID);                 //Puxa do banco as infos do professor
    ~Professor();

    std::string GetNome();
    string GetDisciplina(int Index);              //Retorna as disciplinas que o professor leciona
    Matrix<bool> GetQuadroHorario();            //Retorna o Quadro de Horário atual
    Matrix<bool> GetRestricao();                //Retorna as restricoes de horario

    void SetQuadroHorario(Matrix<bool> A);      //Salva o Quadro de Horário (organizado pelo PSO)
    void SetNome(std::string nome);
    void SetDisciplina(std::string disciplina);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3, std::string Disciplina4);
};

#endif // PROFESSOR_H
