#include <iostream>

void run21() {
    unsigned int a, b, c;
    std::cin >> a >> b >> c;
    if (a % c == 0) {
        if (b % c == 0) {
            std::cout << (a + b) / c;
        } else {
            std::cout << a / c + b;
        }
    } else {
        std::cout << a - b - c;
    }
}

void run22() {
    unsigned short n;
    std::cin >> n;
    switch (n) {
        case 1:
            std::cout << "one";
            break;
        case 2:
            std::cout << "two";
            break;
        case 3:
            std::cout << "three";
            break;
        case 4:
            std::cout << "four";
            break;
        case 5:
            std::cout << "five";
            break;
        case 6:
            std::cout << "six";
            break;
        case 7:
            std::cout << "seven";
            break;
        case 8:
            std::cout << "eight";
            break;
        case 9:
            std::cout << "nine";
            break;
        case 0:
            std::cout << "zero";
            break;
        default:
            std::cout << "wrong input";
    }
}