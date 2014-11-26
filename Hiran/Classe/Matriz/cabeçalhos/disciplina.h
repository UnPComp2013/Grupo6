#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>
#include <Headers/primitiveLibs/matrix.h>
#include <Headers/professor.h>

class Disciplina
{
    Professor professor;
    std::string nome;
    int cargaHoraria;
    bool aulaPratica;
    //Matrix<bool> QuadroHorario;

    //Professor professores;

public:
    Disciplina();
    //~Disciplina();
    std::string getNome();
    int getCargaHoraria();
    void setCargaHoraria(int CH);
    void setNome(std::string nome);
    bool getPraticaOuNao();                     //true para aula pratica, false para normal

    Professor getProfessor();
    void setProfessor(Professor professor);

    int ocupacao1NaColuna[5], ocupacao2NaColuna[5];           //Define como a disciplina vai ser ocupada no quadro de horário dependendo da carga horária


};

#endif // DISCIPLINA_H

