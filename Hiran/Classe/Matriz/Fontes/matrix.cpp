#include "matrix.h"
//construtor
template<class TipoVariavel>
Matrix<TipoVariavel>::Matrix()
{
    this->rows = 0;
    this->cols = 0;
}
//segundo construtor
template<class TipoVariavel>
Matrix<TipoVariavel>::Matrix(unsigned rows, unsigned cols)
{
    this->Alloc(rows, cols);
}
//destrutor
template<class TipoVariavel>
Matrix<TipoVariavel>::~Matrix()
{
    for(unsigned i = 0; i< this->rows; i++)
        delete Mat[i];

    for(unsigned j = 0; j< this->cols; j++)
        delete Mat[j];

    delete Mat;

}
template<class TipoVariavel>
void Matrix<TipoVariavel>::Alloc(unsigned rows, unsigned cols)
{
    try
    {
        this->Mat = new bool*[cols];
        for(unsigned i = 0; i < cols; ++i)
            this->Mat[i] = new bool[rows];

        this->rows = rows;
        this->cols = cols;
    }
    catch (std::bad_alloc&)
    {
        std::cout << "erro na alocação";
    }
}
//operador de comparação & determina se algum termo da matriz é igual
template<class TipoVariavel>
Matrix<TipoVariavel> Matrix<TipoVariavel>::operator&(Matrix M)
{
    Matrix<TipoVariavel> ret;
        ret.Alloc(this->rows,this->cols);

        for(int i = 0; i < this->rows; i++)
            for(int j = 0; j < this->cols; j++)
              ret.Mat[i][j] = (bool)this->Mat[i][j] &(bool)M.Mat[i][j];

        return ret;
}
//operador de igualdade
template<class TipoVariavel>
Matrix<TipoVariavel> Matrix<TipoVariavel>::operator=(Matrix A)
{   
    Matrix<TipoVariavel> ret;

    ret.Alloc(A.rows, A.cols);

    for(unsigned i = 0; i < A.rows; i++)
        for(unsigned j = 0; j < A.cols; j++)
            ret.Mat[i][j] = A.Mat[i][j];

    return ret;
}

/*void Matrix::InitMat(unsigned rows, unsigned cols)
{
    this->Mat = new bool *[rows];
    for(unsigned i = 0; i < rows; i++)
        this->Mat[i] = new bool[cols];
}:*///
void Matrix::InitMat(unsigned rows, unsigned cols)
{
    this->Mat = new bool *[rows];
    for(unsigned i = 0; i < rows; i++)
        this->Mat[i] = new bool[cols];
}
template<class TipoVariavel>
void Matrix<TipoVariavel>::Add(unsigned rows, unsigned cols, bool valor)
{
    {
         Matrix<TipoVariavel> temp;
         unsigned MaxLin = rows, MaxCol = cols;

         if( this-> rows >= MaxLin && this->cols >= MaxCol)
             this->Mat[rows][cols] = valor;

         else{
             if(this->rows > MaxLin)
                 MaxLin = this->rows;

             if(this->cols > MaxCol)
                 MaxCol = this->cols;

             temp.InitMat(MaxLin,MaxCol);

             for(unsigned i = 0; i < MaxLin; i++)
                 for(unsigned j =0; j < MaxCol; j++)
                     temp.Mat[i][j] = this->Mat[i][j];

             temp.Mat[rows][cols] = valor;
             this->InitMat(MaxLin, MaxCol);

             for(unsigned i = 0; i < MaxLin; i++)
                 for(unsigned j =0; j < MaxCol; j++)
                     this->Mat[i][j] = temp.Mat[i][j];

             }
    }
}
