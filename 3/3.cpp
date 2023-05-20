#include "iostream"

void run3() {
    unsigned int a, max = 0, max_i = 0, n;
    unsigned long long mlt = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (a % 5 != 0) {
            if (a > max) {
                max = a;
                max_i = i;
            }
            if (mlt == 0) {
                mlt = a;
            } else {
                mlt *= a;
            }
        }
    };
    std::cout << mlt << " " << max << " " << max_i + 1;
}