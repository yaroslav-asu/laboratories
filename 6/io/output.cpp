#include "iostream"

using namespace std;

namespace io{
    void print_matrix(int **matrix, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

}
