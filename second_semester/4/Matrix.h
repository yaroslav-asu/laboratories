#ifndef LABORATORIES_MATRIX_H
#define LABORATORIES_MATRIX_H

#include <iostream>


template<typename T, int N, int M>
class Matrix {
private:
    T type;
public:
    T **elems;

    Matrix();

    ~Matrix();

    Matrix(Matrix &);

    Matrix &operator=(Matrix const &);

    Matrix *operator+(Matrix &);

    Matrix *operator+=(Matrix &);

    Matrix *operator*(Matrix &);

    Matrix &operator*=(Matrix &);

    void operator++(int);

    long long determinant();

    T *operator[](int row);
};



template<typename T, int N, int M>
std::istream &operator>>(std::istream &is, const Matrix<T, N, M> &matrix);

template<typename T, int N, int M>
std::ostream &operator<<(std::ostream &os, const Matrix<T, N, M> &matrix);

void run_4();

#endif //LABORATORIES_MATRIX_H
