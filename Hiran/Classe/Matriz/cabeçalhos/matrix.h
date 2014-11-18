#define MATRIX_H
#include <iostream>

template<class TipoVariavel>
class Matrix
{
    unsigned rows, cols;
    TipoVariavel **Mat;

public:

    Matrix();
    Matrix(unsigned rows, unsigned cols);
    ~Matrix();
    Matrix operator & (Matrix<TipoVariavel> M);
    Matrix operator = (Matrix<TipoVariavel> A);

    void Alloc(unsigned rows, unsigned cols);
    void Add(unsigned rows, unsigned cols, bool valor);
    void InitMat(unsigned rows, unsigned cols);

};

#endif // MATRIX_H
