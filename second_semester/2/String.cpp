#include <cstring>
#include "String.h"
#include "iostream"

String::String() {
    this->str = nullptr;
    this->size = 0;
}

String::String(char *str) {
    this->size = strlen(str);
    if (this->str == nullptr) {
        this->str = new char[1];
        this->str[0] = '\0';
    } else {
        this->str = new char[this->size + 1];
        std::strcpy(this->str, str);
        this->str[this->size] = '\0';
    }
}

String::String(const String &str) {
    this->str = str.str;
    this->size = str.size;
}

String &String::operator=(const String &str) {
    this->size = str.size;
    this->str = str.str;
    return *this;
}

String::~String() {
    delete this->str;
}

unsigned int String::length() const {
    return this->size;
}

char *String::c_str() {
    return this->str;
}

String &String::operator+(const String &str) {
    char *tmp = new char[this->size + str.size];
    for (int i = 0; i < this->size; ++i) {
        tmp[i] = this->str[i];
    }
    for (int i = 0; i < str.size; ++i) {
        tmp[this->size + i] = str.str[i];
    }
    this->size += str.size;
    tmp[this->size] = '\0';
    this->str = tmp;
    return *this;
}

String &String::operator+=(const String &str) {
    return *this + str;
}

char String::operator[](unsigned int id) {

    return this->str[id];
}

char String::at(int id) {
    if (id < (int)this->size || (int)this->size + id < (int)this->size) {
        if (id >= 0) {
            return (*this)[id];
        } else {
            return (*this)[this->size + id];
        }
    }
    return '\0';
}

std::ostream &operator<<(std::ostream &os, String &str) {
    for (int i = 0; i < str.size; ++i) {
        os << str.str[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, String &str) {
    char *tmpString = new char[256];
    is.getline(tmpString, 256);
    str.str = tmpString;
    str.size = strlen(tmpString);
    return is;
}

int String::find(char symbol) {
    for (int i = 0; i < this->size; ++i) {
        if (this->str[i] == symbol) {
            return i;
        }
    }
    return -1;
}

bool String::operator==(const String &str) {
    if (this->size == str.size) {
        for (int i = 0; i < this->size; ++i) {
            if (this->str[i] != str.str[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool String::operator<(const String &str) {
    unsigned int minSize = str.size;
    if (this->size < str.size) {
        minSize = this->size;
    }
    for (int i = 0; i < minSize; ++i) {
        if (this->str[i] > str.str[i]) {
            return false;
        }
    }
    return this->size == minSize;
}

bool String::operator>(const String &str) {
    return *this < str && !(*this == str);
}
