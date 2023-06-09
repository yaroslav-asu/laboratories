#ifndef LABORATORIES_SHAPE_H
#define LABORATORIES_SHAPE_H


#include <string>

class Shape {
protected:
    float size;
    std::string color;

public:
    explicit Shape(std::string color);

    Shape(std::string color, float size);

    virtual float square();
};
void shape();

#endif //LABORATORIES_SHAPE_H
