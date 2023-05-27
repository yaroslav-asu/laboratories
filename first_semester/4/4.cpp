#include "iostream"

void run41() {
    int n;
    std::cin >> n;
    int a[n];
    int equal_digits_counter = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        a[i] = tmp;
        short last_digit = -1;
        bool all_digits_equal = true;
        while (tmp > 0) {
            if (last_digit == -1) {
                last_digit = tmp % 10;
            } else if (last_digit != tmp % 10) {
                all_digits_equal = false;
                break;
            }
            tmp /= 10;
        }
        if (all_digits_equal) {
            equal_digits_counter++;
        }
        if (equal_digits_counter > 2) {
            break;
        }
    }
    if (equal_digits_counter >= 3) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] < a[j]) {
                    std::swap(a[i], a[j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}
namespace forthTask{
    int num_sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}

int min_num_digit(int num) {
    int min;
    while (num > 0) {
        min = num % 10;
        num /= 10;
    }
    return min;
}

void run42() {
    int n;
    std::cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum_i = forthTask::num_sum(a[i]), sum_j = forthTask::num_sum(a[j]);
            if (sum_i > sum_j) {
                std::swap(a[i], a[j]);
            } else if (sum_i == sum_j) {
                int min_i = min_num_digit(a[i]), min_j = min_num_digit(a[j]);
                if ((min_i > min_j) || (min_i == min_j && a[i] > a[j])) {
                    std::swap(a[i], a[j]);
                }
            }
        }
    }
}

void run43() {
    unsigned short n, m;
    std::cin >> n >> m;
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    unsigned int max_mlt_i;
    long max_mlt = 0;
    for (int i = 0; i < n; i++) {
        long mlt = 1;
        for (int j = 0; j < m; j++) {
            mlt *= matrix[j][i];
        }
        if (mlt > max_mlt) {
            max_mlt_i = i;
        }
    }
    for (int j = 0; j < m; j++) {
        matrix[j][max_mlt_i] -= 3;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
};