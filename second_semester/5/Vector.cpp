#include <iostream>
#include "Vector.h"

Vector::Vector() {
    this->_values = new unsigned char[1];
}

void Vector::expandBuffer() {
    unsigned char tmp[this->_size / 8];
    for (int i = 0; i < _size / 8; i++) {
        tmp[i] = this->_values[i];
    }
    delete this->_values;
    this->_values = new unsigned char[_size / 8 + 5];
    for (long long i = 0; i < _size / 8; i++) {
        this->_values[i] = tmp[i];
    }
    this->bufferSize = 8;
}

void Vector::pushBack(bool newVal) {
    if (bufferSize == 0) {
        this->expandBuffer();
    }
    if (newVal) {
        this->_values[this->_size / 8] |= (1 << (this->_size % 8));
    } else {
        this->_values[this->_size / 8] &= ~(1 << (this->_size % 8));
    }
    this->_size++;
    this->bufferSize--;
}

bool Vector::operator[](long long index) {
    return this->get(index);
}

long long Vector::size() const {
    return this->_size;
}

bool Vector::get(long long index) {
    return this->_values[index / 8] & (1 << (index % 8));
}

void Vector::erase(long long int index) {
    bool tmp[this->_size - index - 1];
    for (long long i = index; i < this->_size; ++i) {
        tmp[i - index] = bool((1 << ((i + 1) % 8)) & this->_values[i / 8]);
    }
    for (long long i = index; i < this->_size; ++i) {
        if (tmp[i - index]) {
            this->_values[i / 8] |= (1 << (i % 8));
        } else {
            this->_values[i / 8] &= ~(1 << (i % 8));
        }
    }
    this->_size--;
    this->bufferSize++;
}

void Vector::print() {
    for (int i = 0; i < this->_size; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < this->_size; ++i) {
        std::cout << bool(this->get(i)) << " ";
        for (int j = i; j >= 10; j /= 10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

}

void Vector::insert(long long int index, bool value) {
    bool tmp[this->_size - index];
    for (long long i = index; i < this->_size + 1; ++i) {
        tmp[i - index] = bool((1 << (i % 8)) & this->_values[i / 8]);
    }
    if (this->bufferSize == 0) {
        expandBuffer();
    }
    if (value) {
        this->_values[index / 8] |= (1 << (index % 8));
    } else {
        this->_values[index / 8] &= ~(1 << (index % 8));
    }
    for (long long i = index + 1; i < this->_size + 2; ++i) {
        if (tmp[i - index - 1]) {
            this->_values[i / 8] |= (1 << (i % 8));
        } else {
            this->_values[i / 8] &= ~(1 << (i % 8));
        }
    }
    this->_size++;
    this->bufferSize--;
}

void run_vector(){
    Vector a = Vector();
    for (int j = 0; j < 8; ++j) {
        a.pushBack(true);
        a.pushBack(false);
    }
    a.print();
    a.erase(2);
    a.print();
    a.insert(2, true);
    a.print();
}
