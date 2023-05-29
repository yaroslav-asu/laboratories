#ifndef LABORATORIES_COMPLEX_H
#define LABORATORIES_COMPLEX_H


#include <iostream>

class Complex {
private:
    int real, imaginary;
public:
    Complex(int, int);

    Complex(Complex &);

    Complex &operator=(const Complex &);

    ~Complex();

    Complex &operator+=(const Complex &complex);

    Complex &operator+(const Complex &complex) const;

    Complex &operator*(const Complex &complex) const;

    Complex &operator*=(const Complex &complex);

    Complex &operator++();

    Complex operator++(int);

    friend std::ostream &operator<<(std::ostream &os, Complex &complex);

    friend std::istream &operator>>(std::istream &is, Complex &complex);
};

void run_3();

#endif //LABORATORIES_COMPLEX_H
