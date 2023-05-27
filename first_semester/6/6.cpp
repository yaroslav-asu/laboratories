#include "iostream"
#include "../4/4.h"
#include "io/io.h"
namespace handle{
    int matrix_max(int **matrix, int size) {
        int max;
        bool was_changed = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] > max || !was_changed) {
                    max = matrix[i][j];
                    was_changed = true;
                }
            }
        }
        return max;
    }

    int matrix_min(int **matrix, int size) {
        int min;
        bool was_changed = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] < min || !was_changed) {
                    min = matrix[i][j];
                    was_changed = true;
                }
            }
        }
        return min;
    }

    int row_sum(int *row, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += row[i];
        }
        return sum;
    }

    void sort_matrix(int **matrix, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (row_sum(matrix[i], size) > row_sum(matrix[j], size)) {
                    std::swap(matrix[i], matrix[j]);
                }
            }
        }
    }
}

void run6() {
    short n;
    std::cin >> n;
    int **matrix;
    matrix = io::input_matrix(n);
    if (forthTask::num_sum(handle::matrix_max(matrix, n)) == forthTask::num_sum(handle::matrix_min(matrix, n))) {
        handle::sort_matrix(matrix, n);
    }
    io::write_matrix(matrix, n);
}