#include "Shape.h"
#include "triange/Triangle.h"
#include "circle/Circle.h"
#include "square/Rectangle.h"

Shape::Shape(std::string color) {
    this->color = color;
    this->size = 1;
}

Shape::Shape(std::string color, float size) : Shape(color) {
    this->size = size;
}


float Shape::square() { return 0; }

void shape(){
    triangle();
    circle();
    rectangle();
}
