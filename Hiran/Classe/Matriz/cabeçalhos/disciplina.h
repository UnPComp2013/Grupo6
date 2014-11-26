#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>
#include <Headers/primitiveLibs/matrix.h>
#include <Headers/professor.h>

/*! Classe Disciplina */
class Disciplina
{
    Professor professor;
    std::string nome;
    int cargaHoraria;
    bool aulaPratica;
    //Matrix<bool> QuadroHorario;
    //Professor professores;

public:
    //! Constructor.
       /*!
         .
       */
    Disciplina();
    //~Disciplina();
    //! Função que pega o nome da disciplinas, não possui parâmetros de entrada retorna o nome.
    /*!
     * \brief getNome
     * \return nome
     */
    std::string getNome();
    //! Pega a carga horaria da disciplina, não possui parâmetros de entrada retorna a carga horaria.
    /*!
     * \brief getCargaHoraria
     * \return cargaHoraria
     */
    int getCargaHoraria();
    //! Entra com a carga horaria da disciplinas, parâmetro de entrada CH (carga horaria).
    /*!
     * \brief setCargaHoraria
     * \param CH
     */
    void setCargaHoraria(int CH);
    //! Entra com o nome da disciplina, não possui parâmetros de entrada retorna o nome.
    /*!
     * \brief setNome
     * \param nome
     */
    void setNome(std::string nome);
    //! Vai pegar o valor (TRUE) se a disciplinas é pratica e (FALSE) se não for, não possui parâmetros de entrada retorna o nome.
    /*!
     * \brief getPraticaOuNao
     * \return aulaPratica
     */
    bool getPraticaOuNao();                     //true para aula pratica, false para normal
    //! Pega os professores que dão aula dessa disciplina, não possui parâmetros de entrada retorna o nome.
    /*!
     * \brief getProfessor
     * \return professor
     */
    Professor getProfessor();
    //! Entra com os professores que podem da aula daquela disciplinas, parâmetro de entrada professor.
    /*!
     * \brief setProfessor
     * \param professor
     */
    void setProfessor(Professor professor);

    int ocupacao1NaColuna[5], ocupacao2NaColuna[5];           //Define como a disciplina vai ser ocupada no quadro de horário dependendo da carga horária


};

#endif // DISCIPLINA_H

