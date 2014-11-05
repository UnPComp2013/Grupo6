#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template<class TipoVariavel>
class Matrix
{
private:
    unsigned rows, cols;
    TipoVariavel **Mat; //Separa um espaço com tipo variavel
    //double **Mat;

public:
    Matrix();
    ~Matrix();
    Matrix(unsigned rows, unsigned cols);
    Matrix operator& (Matrix<TipoVariavel> M);
    Matrix operator* (Matrix<TipoVariavel> M);
    Matrix operator* (TipoVariavel a);
    
    friend Matrix operator *(TipoVariavel a, Matrix M){return M*a;}
    
    void    print();
    void    alloc(unsigned rows, unsigned cols);
    void    add(unsigned row, unsigned col, TipoVariavel value);

};

#endif // MATRIX_H
