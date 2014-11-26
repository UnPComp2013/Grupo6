#ifndef TURMA_H
#define TURMA_H

#include <iostream>
#include <string>
#include <Headers/disciplina.h>
#include <Headers/professor.h>
#include <Headers/primitiveLibs\matrix.h>

class Turma : public Professor, public Disciplina
{
    std::string nome;
    int QuantidadeDeDisciplinas, QuantidadeDeProfessores;

public:
    //! Primeiro Constructor.
    /*!
     * \brief Turma
     */
    Turma();
    //! Segundo Constructor.
    /*! Vai procurar no banco de dados pelos dados necessários para forma uma turma, professores,
     * disciplinas depois vai criar a turma com esses dados.
     * \brief Turma
     * \param nome
     */
    Turma(std::string nome);
    //! Destructor.
    /*!
      */
    ~Turma();
    //! Vai pegar a quantidade de disciplinas para aquela turma.
    /*!
     * \brief GetQuantidadeDeDisciplinas
     * \return QuantidadeDeDisciplinas
     */
    int GetQuantidadeDeDisciplinas(){ return this->QuantidadeDeDisciplinas; }
    //! Pega a quantidade de professores.
    /*!
     * \brief GetQuantidadeDeProfessores
     * \return QuantidadeDeProfessores
     */
    int GetQuantidadeDeProfessores(){ return this->QuantidadeDeProfessores; }

    Disciplina *Disciplinas; //!< Disciplinas ponteiro de disciplinas
    Professor *Professores; //!< Professor ponteiro de professores
    Matrix<char> QuadroDeHorarioTurma;  //! Matriz de tipo character com o quadro de rorarios da turma.
    //Só poderá ser setado valores pelo banco ou pela interface do programa através do construtor
    //void setQuantidadeDisciplinas(unsigned QuantidadeDeDisciplinas);
    //void setQuantidadeProfessores(unsigned QuantidadeDeProfessores);
};

#endif // TURMA_H
