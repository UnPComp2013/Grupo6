#ifndef AVALIA_H
#define AVALIA_H

#include <turma.h>
#include <primitiveLibs/matrix.h>

class avalia
{
    Turma *turma;
    Matrix<bool> restricoes;
    int punicao;

public:
    avalia(string nomeTurma);
    ~avalia();
    void initQuadroHorario();
    void classificarHoraDaDisciplina(Disciplina &disciplina);              //Divide a Disciplina dependendo da carga horaria
    void restricoesDoProf();                    //Compara o quadro com as restrições do professor
    void organizarQuadro();

    Disciplina **QuadroDeHorario;          //Matriz de disciplinas
};

#endif // AVALIA_H
