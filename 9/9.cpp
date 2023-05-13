#include "iostream"

using namespace std;

class Triangle {
private:
    float side1;
    float side2;
    float side3;

    static bool can_exist(float side1, float side2, float side3) {
        return side1 < side2 + side3 &&
               side2 < side1 + side3 &&
               side3 < side1 + side2;
    }

    float perimetr() {
        return side1 + side2 + side3;
    }


public:
    Triangle(float side1, float side2, float side3) {
        if (can_exist(side1, side2, side3)) {
            this->side1 = side1;
            this->side2 = side2;
            this->side3 = side3;
        } else {
            cout << "Triangle doesn't exist" << endl;
            this->side1 = -1;
            this->side2 = -1;
            this->side3 = -1;
        }
    }

    void print_perimetr() {
        float triangle_perimetr = perimetr();
        if (triangle_perimetr != -3){
            cout << triangle_perimetr << endl;
        }else{
            cout << "Perimetr doesn't exist";
        }
    }


};

void run9() {
    Triangle my_triangle(0.5, 1, 1.4);
    my_triangle.print_perimetr();
}