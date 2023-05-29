#include <iostream>
#include "second_semester/2/String.h"

int main() {
    char a[2]{'a', '\0'};
    String A = String(a);
    String B = String();
    std::cin >> B;
    A += B;
    std::cout << A.length() << std::endl;
    std::cout << A.c_str() << std::endl;
    std::cout << A.at(-1) << std::endl;
    std::cout << A[0] << std::endl;
    std::cout << A << std::endl;
    std::cout << A.find('b') << std::endl;
    std::cout << (A == B) << std::endl;
    std::cin >> A >> B;
    std::cout << (A < B) << std::endl;
    std::cout << (A == B) << std::endl;
    return 0;
}