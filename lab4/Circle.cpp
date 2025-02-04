#include "Circle.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) : radius(r) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

double Circle::getCircumference() const {
    return 2 * M_PI * radius;
}

void Circle::printInfo(std::ofstream& out) const {
    out << "Коло:\n";
    out << "Радіус: " << radius << "\n";
    out << "Площа: " << getArea() << "\n";
    out << "Довжина кола: " << getCircumference() << "\n\n";
}
