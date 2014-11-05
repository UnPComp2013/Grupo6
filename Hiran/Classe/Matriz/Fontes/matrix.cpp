#include "matrix.h"

Matrix::Matrix()
{
    this->rows = 0;
    this->cols = 0;
}
Matrix::Matrix(unsigned rows, unsigned cols)
{
    this->alloc(rows, cols);
}

Matrix::~Matrix()
{
    for(unsigned i = 0; i< this->rows; i++)
        delete Mat[i];

    for(unsigned j = 0; j< this->cols; j++)
        delete Mat[j];

    delete Mat;

}
//Erro com o try e o catch.
void Matrix::Alloc(unsigned rows, unsigned cols)
{
    //try
    //{
        this->Mat = new bool*[cols];
        for(unsigned i = 0; i < cols; ++i)
            this->Mat[i] = new bool[rows];

        this->rows = rows;
        this->cols = cols;
    //}
    //catch (std::bad_alloc&)
    //{
      //  std::cout << "erro na alocação";
    //}
}


Matrix Matrix::operator&(Matrix M)
{
    Matrix ret;
        ret.InitMat(this->rows,this->cols);

        for(int i = 0; i < this->rows; i++)
            for(int j = 0; j < this->cols; j++)
              ret.Mat[i][j] = (bool)this->Mat[i][j] &(bool)M.Mat[i][j];

        return ret;
}

Matrix Matrix::operator=(Matrix A)
{   
    Matrix ret;

    ret.Alloc(A.rows, A.cols);

    for(unsigned i = 0; i < A.rows; i++)
        for(unsigned j = 0; j < A.cols; j++)
            ret.Mat[i][j] = A.Mat[i][j];

    return ret;
}

void Matrix::InitMat(unsigned rows, unsigned cols)
{
    this->Mat = new bool *[rows];
    for(unsigned i = 0; i < rows; i++)
        this->Mat[i] = new bool[cols];
}
void Matrix::Add(unsigned rows, unsigned cols, bool valor)
{
    {
         Matrix temp;
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
