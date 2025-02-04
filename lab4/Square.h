#ifndef SQUARE_H
#define SQUARE_H

#include "Figura.h"

class Square : public Figura {
private:
    double side;

public:
    Square(double s);
    double getArea() const;
    double getPerimeter() const;
    double getInscribedCircleRadius() const;
    void printInfo(std::ofstream& out) const override;
};

#endif // SQUARE_H
