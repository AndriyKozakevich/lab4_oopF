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
    out << "�������:\n";
    out << "�������: " << side << "\n";
    out << "�����: " << getArea() << "\n";
    out << "��������: " << getPerimeter() << "\n";
    out << "����� ��������� ����: " << getInscribedCircleRadius() << "\n\n";
}
