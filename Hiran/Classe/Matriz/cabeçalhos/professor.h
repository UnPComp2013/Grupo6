#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include <Headers/primitiveLibs\matrix.h>
#include <string>
/*! Classe Professor */
//template <class TipoDaClasse>
class Professor
{
    unsigned        ID,             QuantidadeDisciplinas;      //Informações do professor
    std::string     nome,           *Disciplinas;
    Matrix<bool>    QuadroHorario,  restricoes;                 //Matriz de restrição e horário
    //Disciplina disciplinas[];

public:
    //!Primeiro construtor de inicialiação, valores em branco.
    /*!
     * \brief Professor
     */
    Professor();
    //!Segundo construtor, fará uma busca no banco através do ID recebido.Valores Temporarios.
    /*!
     * \brief Professor
     * \param ID
     */
    Professor(unsigned ID);                             //Puxa do banco as infos do professor
    //! Destructor
    ~Professor();
    //! Função que retorna o nome do professor.
    /*!
     * \brief GetNome
     * \return nome
     */
    string          GetNome();
    //! Função que retorna as disciplinas que o professor leciona.
    /*!
     * \brief GetDisciplina
     * \param Index
     * \return Disciplinas[Index]
     */
    string          GetDisciplina(int Index);           //Retorna as disciplinas que o professor leciona
    //! Função que retorna o quadro de horário atual
    /*!
     * \brief GetQuadroHorario
     * \return QuadroHorario
     */
    Matrix<bool>    GetQuadroHorario();                 //Retorna o Quadro de Horário atual
    //! Função que retorna as restrições de horário
    /*!
     * \brief GetRestricao
     * \return restricoes
     */
    Matrix<bool>    GetRestricao();                     //Retorna as restricoes de horario
    //! Função que retorna a quantidade exata de disciplinas
    /*!
     * \brief getQuantidadeDisciplinas
     * \return QuantidadeDisciplinas
     */
    int             getQuantidadeDisciplinas();         //Retorna a quantidade exata de disciplinas
    //! Entra com o nome do professor.
    /*!
     * \brief SetNome
     * \param nome
     */
    void SetNome(std::string nome);
    //! Entra com o quadro de horário (organizado pelo PSO).
    /*!
     * \brief SetQuadroHorario
     * \param A
     */
    void SetQuadroHorario(Matrix<bool> A);              //Salva o Quadro de Horário (organizado pelo PSO)
    //! Entra com o nome da disciplina que o professor da aula.
    /*!
     * \brief SetDisciplina
     * \param disciplina
     */
    void SetDisciplina(std::string disciplina);
    //! Entra com as disciplinas que o professor da aula.
    /*!
     * \brief SetDisciplina
     * \param QntDeDisciplinas
     * \param Disciplina1
     * \param Disciplina2
     */
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2);
    //! Entra com as disciplinas que o professor da aula.
    /*!
     * \brief SetDisciplina
     * \param QntDeDisciplinas
     * \param Disciplina1
     * \param Disciplina2
     * \param Disciplina3
     */
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3);
    //! Entra com as disciplinas que o professor da aula.
    /*!
     * \brief SetDisciplina
     * \param QntDeDisciplinas
     * \param Disciplina1
     * \param Disciplina2
     * \param Disciplina3
     * \param Disciplina4
     */
    void SetDisciplina(unsigned QntDeDisciplinas, std::string Disciplina1, std::string Disciplina2, std::string Disciplina3, std::string Disciplina4);
};

#endif // PROFESSOR_H
