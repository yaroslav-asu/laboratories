#ifndef LABORATORIES_VECTOR_H
#define LABORATORIES_VECTOR_H


class Vector {
private:
    unsigned char *_values;
    long long _size = 0;
    unsigned short bufferSize = 8;

    void expandBuffer();

public:
    Vector();

    void pushBack(bool);

    bool get(long long index);

    long long size() const;

    void insert(long long index, bool value);

    void erase(long long index);

    bool operator[](long long index);

    void print();
};

void run_vector();

#endif //LABORATORIES_VECTOR_H
