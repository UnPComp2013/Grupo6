#include "matrix.h"

Matrix::Matrix()
{
}
Matrix::~Matrix()
{

}
Matrix Matrix::operator &(Matrix M)
{
    
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

         if( this-> rows >= MaxLin && this->cols >= MaxCol){
             for(unsigned i = 0; i < MaxLin; i++)
                 for(unsigned j =0; j < MaxCol; j++)
                     temp.Mat[i][j] = this->Mat[i][j];

         }

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
