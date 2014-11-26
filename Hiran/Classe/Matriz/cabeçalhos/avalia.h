#ifndef AVALIA_H
#define AVALIA_H

#include <Headers/turma.h>
#include <Headers/primitiveLibs/matrix.h>

/*! Classe Avalia */
class avalia
{
    int punicao;
    Turma *turma;
    Matrix<bool> restricoes;


public:
    //! Primeiro Constructor.
    /*!
     * \brief avalia
     */
    avalia();
    //! Segundo Constructor.
    /*!
     * Esse construtor fara a criação da turma e alocara o espaço na memória onde cera
         Armazenada a turma logo após será feita a organização dos horários.
     * \brief avalia
     * \param nomeTurma
     */
    avalia(string nomeTurma);
    //! Destructor
        /*!
         */
    ~avalia();
    //! Uma função de organização, não possuindo parâmetros de entrada e nem de saída.
         /*!
     * \brief organizarQuadro
     */
    void organizarQuadro();
    //! Função de avaliação das restrções, não possuindo parâmetros de entrada e nem de saída.
    /*!
     * \brief restricoesDoProf
     */
    void restricoesDoProf();                    //Compara o quadro com as restrições do professor
    //! Função responsavem por allocar os espaços para os quadros de horario, não possuindo parâmetros de entrada e nem de saída.
    /*!
     * \brief initQuadroHorario
     */
    void initQuadroHorario();
    //! .
    /*!
     * \brief MontarQuadro
     * \param x
     * \return QuadroDeHorario
     */
    bool MontarQuadro(int x);
    //!Função responsável por classificar os horários com base na carga horaria e se a disciplinas é pratica ou não, parâmetro de entrada a disciplinas
    /*!
     * \brief classificarHoraDaDisciplina
     * \param disciplina
     */
    void classificarHoraDaDisciplina(Disciplina &disciplina);              //Divide a Disciplina dependendo da carga horaria
    //!Função responsável por declarar o professor ou professores que lecionaram a disciplina, parâmetro de entrada disciplinas.
    /*!
     * \brief classificarProfessorDaDisciplina
     * \param disciplina
     */
    void classificarProfessorDaDisciplina(Disciplina &disciplina);    //Diz qual professor vai ministrar a disciplina
    //! Função de retorno do erro que o PSO vai retorna um Matriz double.
    /*!
     * \brief AvaliaResultadoPSO
     * \param amostragem
     * \return Matrix2Evaluate
     */
    double AvaliaResultadoPSO(Matrix<double>& amostragem);
    //! Função de retorno do erro que o PSO vai retorna uma matriz float.
    /*!
     * \brief AvaliaResultadoPSO
     * \param amostragem
     * \return Matrix2Evaluate
     */
    double AvaliaResultadoPSO(Matrix<float>& amostragem);
    Disciplina **QuadroDeHorario;  //!< Matriz de disciplinas
};

#endif // AVALIA_H
