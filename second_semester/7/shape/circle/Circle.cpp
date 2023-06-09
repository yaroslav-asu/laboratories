#include "Circle.h"

#include <cmath>
#include <iostream>

Circle::Circle(std::pair<float, float> center, float radius, std::string color, float size) : Shape(color, size) {
    this->center = center;
    this->radius = radius;
}

float Circle::square() {
    return M_PI * this->size * this->radius * this->radius;
}

void circle() {
    Circle circle = Circle({0, 0}, 1, "", 1);
    std::cout << circle.square() << std::endl;
}