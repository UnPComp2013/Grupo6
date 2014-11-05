#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{

    unsigned rows, cols;
    bool **Mat;

public:

    Matrix();
    Matrix(unsigned rows, unsigned cols);
    ~Matrix();
    Matrix operator & (Matrix M);
    Matrix operator = (Matrix A);

    void Alloc(unsigned rows, unsigned cols);
    void Add(unsigned rows, unsigned cols, bool valor);
    void InitMat(unsigned rows, unsigned cols);

};

#endif // MATRIX_H
