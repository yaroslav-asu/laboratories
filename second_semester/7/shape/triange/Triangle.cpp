#include "Triangle.h"

#include <cmath>
#include <iostream>

Triangle::Triangle(std::pair<float, float> *coords, std::string color, float size) : Shape(color, size) {
    this->first = coords[0];
    this->second = coords[1];
    this->third = coords[2];
}

float Triangle::square() {
    return this->size * 1. / 2. * ((first.first - third.first) * (second.second - third.second) -
                                   (second.first - third.first) * (first.second - third.second));
}

void triangle() {
    std::pair<float, float> coords[3] = {{2,  -3},
                                         {1,  1},
                                         {-6, 5}};
    Triangle t(coords, "", 1);
    std::cout << t.square() << std::endl;
}