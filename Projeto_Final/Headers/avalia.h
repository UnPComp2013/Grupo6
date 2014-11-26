#ifndef AVALIA_H
#define AVALIA_H

#include <turma.h>
#include <primitiveLibs/matrix.h>

class avalia
{
    int punicao;
    Turma *turma;
    Matrix<bool> restricoes;

public:
    avalia();
    avalia(string nomeTurma);
    ~avalia();
    void organizarQuadro();
    void restricoesDoProf();                    //Compara o quadro com as restrições do professor
    void initQuadroHorario();
    bool MontarQuadro(int x);
    void classificarHoraDaDisciplina(Disciplina &disciplina);              //Divide a Disciplina dependendo da carga horaria
    void classificarProfessorDaDisciplina(Disciplina &disciplina);    //Diz qual professor vai ministrar a disciplina

    double AvaliaResultadoPSO(Matrix<double>& amostragem);
    double AvaliaResultadoPSO(Matrix<float>& amostragem);
    Disciplina **QuadroDeHorario;          //Matriz de disciplinas
};

#endif // AVALIA_H
