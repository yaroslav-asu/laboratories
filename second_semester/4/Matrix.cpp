#include "Matrix.h"
#include <iostream>
#include <cmath>


template<typename T, int N, int M>
Matrix<T, N, M>::Matrix() = default;

template<typename T, int N, int M>
Matrix<T, N, M>::Matrix(Matrix &matrix) {
    this->type = matrix.type;
    this->elems = matrix.elems;
}

template<typename T, int N, int M>
Matrix<T, N, M>::~Matrix() = default;

template<typename T, int N, int M>
std::istream &operator>>(std::istream &is, Matrix<T, N, M> &matrix) {
    matrix.elems = new T *[N];
    for (int i = 0; i < N; ++i) {
        matrix.elems[i] = new T[M];
        for (int j = 0; j < M; ++j) {
            is >> matrix.elems[i][j];
        }
    }
    return is;
}

template<typename T, int N, int M>
std::ostream &operator<<(std::ostream &os, const Matrix<T, N, M> &matrix) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            os << matrix.elems[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

template<typename T, int N, int M>
Matrix<T, N, M> &Matrix<T, N, M>::operator=(Matrix const &matrix) {
    this->elems = matrix.elems;
    this->type = matrix.type;
    return *this;
}

template<typename T, int N, int M>
long long Matrix<T, N, M>::determinant() {
    if (N != M) {
        return 0;
    }
    int num1, num2, det = 1, index, total = 1;
    int temp[N + 1];
    for (int i = 0; i < N; i++) {
        index = i;
        while (index < N && this->elems[index][i] == 0) {
            index++;
        }
        if (index == N) {
            continue;
        }
        if (index != i) {
            for (int j = 0; j < N; j++) {
                std::swap(this->elems[index][j], this->elems[i][j]);
            }
            det = det * std::pow(-1, index - i);
        }

        for (int j = 0; j < N; j++) {
            temp[j] = this->elems[i][j];
        }
        for (int j = i + 1; j < N; j++) {
            num1 = temp[i];
            num2 = this->elems[j][i];

            for (int k = 0; k < N; k++) {
                this->elems[j][k] = (num1 * this->elems[j][k]) - (num2 * temp[k]);
            }
            total = total * num1;
        }
    }
    for (int i = 0; i < N; i++) {
        det = det * this->elems[i][i];
    }
    return (det / total);
}

template<typename T, int N, int M>
T *Matrix<T, N, M>::operator[](int row) {
    return this->elems[row];
}


template<typename T, int N, int M>
Matrix<T, N, M> *Matrix<T, N, M>::operator+(Matrix &matrix) {
    auto *_new = new Matrix<T, N, M>();
    (*_new).elems = new T *[N];
    for (int i = 0; i < N; i++) {
        (*_new).elems[i] = new T[M];
        for (int j = 0; j < M; ++j) {
            (*_new)[i][j] = this->elems[i][j] + matrix[i][j];
        }
    }
    return _new;
}

template<typename T, int N, int M>
Matrix<T, N, M> *Matrix<T, N, M>::operator+=(Matrix &matrix) {
    Matrix<T, N, M> _new = *(*(this) + matrix);
    this->elems = _new.elems;
    this->type = _new.type;
    return this;
}

template<typename T, int N, int M>
void Matrix<T, N, M>::operator++(int) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            this->elems[i][j]++;
        }
    }
}

template<typename T, int N, int M>
Matrix<T, N, M> *Matrix<T, N, M>::operator*(Matrix &matrix) {
    auto *_new = new Matrix<T, N, M>();
    (*_new).elems = new T *[N];
    for (int row = 0; row < N; row++) {
        (*_new).elems[row] = new T[M];
        for (int col = 0; col < M; col++) {
            *(_new[row][col]) = 0;
        }
    }
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            for (int inner = 0; inner < ((N < M) ? N : M); inner++) {
                *(_new[row][col]) += *(this)[row][inner] * matrix[inner][col];
            }
        }
    }
    return _new;
}

template<typename T, int N, int M>
Matrix<T, N, M> &Matrix<T, N, M>::operator*=(Matrix &matrix) {
    Matrix<T, N, M> *_new = *this + matrix;
    this->elems = _new->elems;
    this->type = _new->type;
    return *this;
}

void run_4() {
    Matrix<float, 1, 1> a = Matrix<float, 1, 1>();
    Matrix<float, 1, 1> b = Matrix<float, 1, 1>();

    std::cin >> a;
    std::cin >> b;

    a *= b;
    a++;

    std::cout << a.determinant();
}