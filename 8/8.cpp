#include "iostream"

void run8() {
    long long val;
    std::cin >> val;
    unsigned char *bytes = (unsigned char *) (&val);
    for (int i = 0; i < 8; i++) {
        std::cout << int(*(bytes + i)) << " ";
    }
}