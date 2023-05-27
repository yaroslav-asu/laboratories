#include "iostream"
#include <fstream>
#include <filesystem>

namespace io{
    void write_matrix(int **matrix, int size) {
        std::ofstream fout(std::filesystem::current_path().string() + "/../6/out.txt");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fout << matrix[i][j] << " ";
            }
            fout << std::endl;
        }
    }
}
