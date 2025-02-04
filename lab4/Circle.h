#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figura.h"
#include <cmath>

class Circle : public Figura {
private:
    double radius;

public:
    Circle(double r);
    double getArea() const;
    double getCircumference() const;
    void printInfo(std::ofstream& out) const override;
};

#endif // CIRCLE_H
