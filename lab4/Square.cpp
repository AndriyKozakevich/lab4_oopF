#include "Square.h"
#include <iostream>

Square::Square(double s) : side(s) {}

double Square::getArea() const {
    return side * side;
}

double Square::getPerimeter() const {
    return 4 * side;
}

double Square::getInscribedCircleRadius() const {
    return side / 2.0;
}

void Square::printInfo(std::ofstream& out) const {
    out << "Квадрат:\n";
    out << "Сторона: " << side << "\n";
    out << "Площа: " << getArea() << "\n";
    out << "Периметр: " << getPerimeter() << "\n";
    out << "Радіус вписаного кола: " << getInscribedCircleRadius() << "\n\n";
}
