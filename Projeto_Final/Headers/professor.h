#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <primitiveLibs\matrix.h>
#include <string>

//template <class TipoDaClasse>
class Professor
{
    unsigned        ID,             QuantidadeDisciplinas;      //Informações do professor
    std::string     nome,           *Disciplinas;
    Matrix<bool>    QuadroHorario,  restricoes;                 //Matriz de restrição e horário
    //Disciplina disciplinas[];

public:
    Professor();
    Professor(unsigned ID);                             //Puxa do banco as infos do professor
    ~Professor();

    string          GetNome();
    string          GetDisciplina(int Index);           //Retorna as disciplinas que o professor leciona
    Matrix<bool>    GetQuadroHorario();                 //Retorna o Quadro de Horário atual
    Matrix<bool>    GetRestricao();                     //Retorna as restricoes de horario
    int             getQuantidadeDisciplinas();         //Retorna a quantidade exata de disciplinas

    void SetNome(std::string nome);
    void SetQuadroHorario(Matrix<bool> A);              //Salva o Quadro de Horário (organizado pelo PSO)
    void SetDisciplina(std::string disciplina);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3);
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3, std::string Disciplina4);
};

#endif // PROFESSOR_H
