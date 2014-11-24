#include "turma.h"

Turma::Turma()
{
    this->nome = "";
    this->QuantidadeDeDisciplinas = 0;
    this->QuantidadeDeProfessores = 0;
    this->QuadroDeHorarioTurma.init(0,0);

    this->Disciplinas = new Disciplina[QuantidadeDeDisciplinas];
    this->Professores = new Professor[QuantidadeDeProfessores];
}

Turma::Turma(std::string nome)
{
    //Faz a pesquisa no pelo nome da disciplina e retorna os valores
    this->nome = nome;
    this->QuantidadeDeDisciplinas = 6;      //Valor Fictício
    this->QuantidadeDeProfessores = 6;      //Valor Fictício
    this->QuadroDeHorarioTurma.init(5,6);   //Valor Fictício

    this->Disciplinas = new Disciplina[this->QuantidadeDeDisciplinas];
    this->Professores = new Professor[this->QuantidadeDeProfessores];

    //---------------------------------------------------------------------//
    //INFORMAÇÕES NECESSÁRIAS DA DISCIPLINA--------------------------------//
    this->Disciplinas[0].setNome("Ciência e Tecnologia dos Materiais");
    this->Disciplinas[1].setNome("Circuitos e instrumentação");
    this->Disciplinas[2].setNome("Equações Diferenciais");
    this->Disciplinas[3].setNome("Fisica II");
    this->Disciplinas[4].setNome("Mecânica dos Fluidos");
    this->Disciplinas[5].setNome("Programação de computadores");

    this->Disciplinas[0].setCargaHoraria(60);
    this->Disciplinas[1].setCargaHoraria(100);
    this->Disciplinas[2].setCargaHoraria(80);
    this->Disciplinas[3].setCargaHoraria(80);
    this->Disciplinas[4].setCargaHoraria(60);
    this->Disciplinas[5].setCargaHoraria(100);
    //FIM DAS INFORMAÇÕES NECESSÁRIAS DA DISCIPLINA------------------------//
    //---------------------------------------------------------------------//

    //---------------------------------------------------------------------//
    //INFORMAÇÕES NECESSÁRIAS DO PROFESSOR---------------------------------//
    this->Professores[0].SetNome("Gilberto");
    this->Professores[1].SetNome("Flávio");
    this->Professores[2].SetNome("Álax Jorge");
    this->Professores[3].SetNome("Alan Cardeque");
    this->Professores[4].SetNome("Amanda");
    this->Professores[5].SetNome("André Felipe");

    for(int i = 0; i < this->QuantidadeDeProfessores; i++)
        this->Professores[i].SetDisciplina(this->Disciplinas[i].getNome());

    //FIM DAS INFORMAÇÕES NECESSÁRIAS DO PROFESSOR-------------------------//
    //---------------------------------------------------------------------//
}

Turma::~Turma()
{
    delete Disciplinas;
    delete Professores;
}
