#ifndef FIGURA_H
#define FIGURA_H

#include <fstream>

class Figura {
public:
    virtual void printInfo(std::ofstream& out) const = 0;
    virtual ~Figura() {}
};

#endif // FIGURA_H
