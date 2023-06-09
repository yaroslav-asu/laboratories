#ifndef LABORATORIES_TRIANGLE_H
#define LABORATORIES_TRIANGLE_H


#include "../Shape.h"

class Triangle : Shape {
private:
    std::pair<float, float> first, second, third;
public:
    Triangle(std::pair<float, float> coords[3], std::string color, float size);
    float square();
};
void triangle();


#endif //LABORATORIES_TRIANGLE_H
