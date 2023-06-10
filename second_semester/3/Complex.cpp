#include "Complex.h"

Complex::Complex(int real, int imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

Complex::Complex(Complex &complex) {
    this->real = complex.real;
    this->imaginary = complex.imaginary;
}

Complex Complex::operator=(const Complex &complex) {
    this->real = complex.real;
    this->imaginary = complex.imaginary;
    return *this;
}

Complex::~Complex() = default;

Complex Complex::operator+=(const Complex &complex) {
    this->real += complex.real;
    this->imaginary += complex.imaginary;
    return *this;
}

Complex Complex::operator+(const Complex &complex) const {
    Complex tmp(this->real + complex.real, this->imaginary + complex.imaginary);
    return tmp;
}

Complex Complex::operator*(const Complex &complex) const {
    Complex tmp = Complex(
            this->real * complex.real - this->imaginary * complex.imaginary,
            this->real * complex.imaginary + this->imaginary * complex.real
    );
    return tmp;
}

Complex Complex::operator*=(const Complex &complex) {
    auto tmp = *this * complex;
    this->real = tmp.real;
    this->imaginary = tmp.imaginary;
    return *this;
}

Complex Complex::operator++() {
    this->real++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++*this;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Complex &complex) {
    os << complex.real << " + " << complex.imaginary << "i";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &complex) {
    is >> complex.real >> complex.imaginary;
    return is;
}


void run_3() {
    Complex a = Complex(Complex(10, 10));
    std::cout << a << std::endl;
    Complex b = Complex(10, 20);
    std::cout << b << std::endl;
    a = b;
    std::cout << a << std::endl;
    Complex c = a + b;
    std::cout << c << std::endl;
    a += b;
    std::cout << a << std::endl;
    a = Complex(1, 1);
    c = a * b;
    std::cout << c << std::endl;
    a *= b;
    std::cout << a << std::endl;
    b++;
    std::cout << b << std::endl;
    c = ++a;
    std::cout << c << std::endl;
}