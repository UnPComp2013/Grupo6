#include "avalia.h"

//------------------------Início dos------------------------//
//----------------Construtores e Destrutores----------------//
avalia::avalia(){}

avalia::avalia(std::string nomeTurma)
{

    this->turma = new Turma(nomeTurma);

    for(int i = 0; i < this->turma->GetQuantidadeDeDisciplinas(); i++)
        classificarHoraDaDisciplina(this->turma->Disciplinas[i]);

    initQuadroHorario();
    organizarQuadro();
}
avalia::~avalia()
{
    for (int i = 0; i < 5; i++)
    {
        free(this->QuadroDeHorario[i]);
        this->QuadroDeHorario[i] = NULL;
    }
    delete this->turma;
    //free( this->turma);
}
//-------------------------Fim dos--------------------------//
//----------------Construtores e Destrutores----------------//

double avalia::AvaliaResultadoPSO(Matrix<double>& amostragem)
{
    return 1;       //aqui onde fará o tratamento do erro
}

double avalia::AvaliaResultadoPSO(Matrix<float>& amostragem)
{
    return 1;       //aqui onde fará o tratamento do erro
}

void avalia::initQuadroHorario()
{
    this->QuadroDeHorario = (Disciplina**)new Disciplina[5];

    for(int i = 0; i < 5; i++)
        this->QuadroDeHorario[i] = new Disciplina[6];
}

void avalia::classificarHoraDaDisciplina(Disciplina &disciplina)
{
    for(int i = 0; i < 5; i++)
    {
        disciplina.ocupacao1NaColuna[i] = 0;
        disciplina.ocupacao2NaColuna[i] = 0;
    }

    if(!disciplina.getPraticaOuNao())
    {
        if(disciplina.getCargaHoraria() > 100 )
        {
            for(int i = 0; i < 5; i++)
                disciplina.ocupacao1NaColuna[i] = 1;
        }
        else if(disciplina.getCargaHoraria() > 80 )
        {
            for(int i = 0; i < 4; i++)
                disciplina.ocupacao1NaColuna[i] = 1;
        }
        else if(disciplina.getCargaHoraria() > 60 )
        {
            for(int i = 0; i < 3; i++)
                disciplina.ocupacao1NaColuna[i] = 1;
        }
        else
        {
            for(int i = 0; i < 2; i++)
                disciplina.ocupacao1NaColuna[i] = 1;
        }
    }
}

void avalia::classificarProfessorDaDisciplina(Disciplina &disciplina)
{
    for(int i = 0; i < this->turma->GetQuantidadeDeProfessores(); i++)
        for(int j = 0; j < this->turma->Professores[i].getQuantidadeDisciplinas(); j++)
            if(this->turma->Professores[i].GetDisciplina(j) == disciplina.getNome())
                disciplina.setProfessor(this->turma->Professores[i]);
}

void avalia::organizarQuadro()
{
    int disciplinaEmQuestao = 0, horarioAtual = 0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            if(this->turma->Disciplinas[disciplinaEmQuestao].ocupacao1NaColuna[horarioAtual] == 1){
                classificarProfessorDaDisciplina(this->turma->Disciplinas[disciplinaEmQuestao]);
                this->QuadroDeHorario[j][i] = this->turma->Disciplinas[disciplinaEmQuestao];
                this->QuadroDeHorario[j][i].setNome(this->QuadroDeHorario[j][i].getNome() + " - \n" +this->QuadroDeHorario[j][i].getProfessor().GetNome());

                if(horarioAtual < 5)
                    horarioAtual++;
                else
                    horarioAtual = 0;

            }else{
                if(disciplinaEmQuestao < 7)
                    disciplinaEmQuestao++;

                horarioAtual = 0;

                if(this->turma->Disciplinas[disciplinaEmQuestao].ocupacao1NaColuna[horarioAtual] == 1){
                    classificarProfessorDaDisciplina(this->turma->Disciplinas[disciplinaEmQuestao]);
                    this->QuadroDeHorario[j][i] = this->turma->Disciplinas[disciplinaEmQuestao];
                    this->QuadroDeHorario[j][i].setNome(this->QuadroDeHorario[j][i].getNome() + " - \n" +this->QuadroDeHorario[j][i].getProfessor().GetNome());

                    if(horarioAtual < 5)
                        horarioAtual++;
                    else
                        horarioAtual = 0;
                }
            }
        }
    }
}

