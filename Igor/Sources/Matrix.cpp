#include "Matrix.h"

template<class TipoVariavel>
Matrix<TipoVariavel>::Matrix()
{
    this->rows = 0;
    this->cols = 0;
    this->Mat = NULL;
}

template<class TipoVariavel>
Matrix<TipoVariavel>::Matrix(unsigned rows, unsigned cols)
{
    alloc(rows, cols);
}

template<class TipoVariavel>
Matrix<TipoVariavel>::~Matrix()
{
    for(unsigned i = 0; i <= this->rows; i++)
    {
        delete[] this->Mat[i];
    }

    delete [] this->Mat;

    this->rows = 0;
    this->cols = 0;
    this->Mat = NULL;
}

template<class TipoVariavel>
void Matrix<TipoVariavel>::alloc(unsigned rows, unsigned cols)
{
    try{
        this->Mat = new TipoVariavel*[cols];
        for(int i = 0; i < cols; i++)
            this->Mat[i] = new TipoVariavel[rows];

        this->rows = rows;
        this->cols = cols;
    }
    catch (std::bad_alloc&)
    {
        std::cout << "erro na alocação";
    }
}

template<class TipoVariavel>
void Matrix<TipoVariavel>::add(unsigned row, unsigned col, TipoVariavel value)
{
     /*if(row > this->rows || col > this->cols)
     {*/
        Matrix Temp;
        unsigned MaxRow = row+1, MaxCol = col+1;

        if(this->rows > MaxRow)
            MaxRow = this->rows;
        if(this->cols > MaxCol)
            MaxCol = this->cols;

        Temp.alloc(MaxRow, MaxCol);

        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->cols; j++)
                Temp.Mat[i][j] = this->Mat[i][j];

        Temp.Mat[row][col] = value;
        this->alloc(MaxRow, MaxCol);

        for(unsigned i = 0; i < this->rows; i++)
            for(unsigned j = 0; j < this->cols; j++)
                this->Mat[i][j] = Temp.Mat[i][j];
    /*}else
        this->Mat[this->rows][this->cols] = value;*/
}
/*
template<class TipoVariavel>
void Matrix<TipoVariavel>::operator &(Matrix Mat)
{

    for( int i = 0; i < this->cols; i++ )
    {
       for( int j = 0; j < this->rows; j++ )
       {
           if(this->Mat[i][j] == Mat[i][j])
               return 1;
           else
               return 0;
       }
    }
}
*/
template<class TipoVariavel>
Matrix<TipoVariavel> Matrix<TipoVariavel>::operator *(TipoVariavel a)
{
    for(unsigned i = 0; i < this->rows; i++)
        for(unsigned j = 0; j < this->cols; j++)
            this->Mat[i][j] *= a;

    return *this;
}

template<class TipoVariavel>
void Matrix<TipoVariavel>::print()
{
    for(unsigned i = 0; i < this->rows; i++){
        for(unsigned j = 0; j < this->cols; j++)
            std::cout << this->Mat[i][j] << "\t";

        std::cout << std::endl;
    }
}

template class Matrix<bool>;
template class Matrix<int>;
