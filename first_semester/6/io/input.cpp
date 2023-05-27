#include "io.h"
#include "iostream"


namespace io {
    int **input_matrix(int size) {
        int **a;
        a = new int *[size];
        for (int i = 0; i < size; i++) {
            a[i] = new int[size];
            for (int j = 0; j < size; j++) {
                std::cin >> a[i][j];
            }
        }
        return a;
    }
}
