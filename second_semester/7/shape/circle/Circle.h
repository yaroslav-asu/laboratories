#ifndef LABORATORIES_CIRCLE_H
#define LABORATORIES_CIRCLE_H


#include "../Shape.h"

class Circle : Shape {
protected:
    std::pair<float, float> center;
    float radius;
public:
    Circle(std::pair<float, float> center, float radius, std::string color, float size);
    float square() override;
};
void circle();


#endif //LABORATORIES_CIRCLE_H
