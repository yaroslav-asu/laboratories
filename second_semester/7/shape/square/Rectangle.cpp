#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(std::pair<float, float> *coords, std::string color, float size) : Shape(color, size) {
    this->first = coords[0];
    this->second = coords[1];
    this->third = coords[2];
    this->fourth = coords[3];
}

float Rectangle::square() {
    return size * (second.first - first.second) * (third.second - second.second) * (third.first - fourth.first) *
           (fourth.second - first.second);
}

void rectangle() {
    std::pair<float, float> coords[4] = {{0, 0},
                                         {1, 0},
                                         {1, 1},
                                         {0, 1}};
    Rectangle rect(coords, "", 1);
    std::cout << rect.square() << std::endl;
}
