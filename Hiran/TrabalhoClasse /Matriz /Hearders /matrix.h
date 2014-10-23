#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
    unsigned rows, cols;
    bool **Mat;

public:
    Matrix();
    ~Matrix();
    Matrix operator& (Matrix M);

    void Add(unsigned rows, unsigned cols, bool valor);
    void InitMat(unsigned rows, unsigned cols);
};

#endif // MATRIX_H
