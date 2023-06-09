#ifndef LABORATORIES_RECTANGLE_H
#define LABORATORIES_RECTANGLE_H


#include "../Shape.h"

class Rectangle : Shape {
protected:
    std::pair<float, float> first, second, third, fourth;
public:
    Rectangle(std::pair<float, float> *coords, std::string color, float size);
    float square() override;
};

void rectangle();
#endif //LABORATORIES_RECTANGLE_H
