#include <matrix.h>

class Professor
{
    Matrix HorarioProfessor, Restricoes, Disciplina;
  
  public:
    Professor();
    ~Professor();
    
    Matrix TabelaHorario      ();                               //Exibe a Matriz com os horarios 
    Matrix CadastroHorario    (bool A);
    Matrix CadastroRestricao  (bool A);
    Matrix PosicaoRestricao   (unsigned row, unsigned col)      //Retorna a posicao da restricao
    
    bool ExisteRestricoes(Matrix A)                             //Verifica se há alguma restrição para este professor
    
}
