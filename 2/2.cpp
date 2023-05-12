#include <iostream>

using namespace std;

void run21() {
    unsigned int a, b, c;
    cin >> a >> b >> c;
    if (a % c == 0) {
        if (b % c == 0) {
            cout << (a + b) / c;
        } else {
            cout << a / c + b;
        }
    } else {
        cout << a - b - c;
    }
}

void run22() {
    unsigned short n;
    cin >> n;
    switch (n) {
        case 1:
            cout << "one";
            break;
        case 2:
            cout << "two";
            break;
        case 3:
            cout << "three";
            break;
        case 4:
            cout << "four";
            break;
        case 5:
            cout << "five";
            break;
        case 6:
            cout << "six";
            break;
        case 7:
            cout << "seven";
            break;
        case 8:
            cout << "eight";
            break;
        case 9:
            cout << "nine";
            break;
        case 0:
            cout << "zero";
            break;
        default:
            cout << "wrong input";
    }
}