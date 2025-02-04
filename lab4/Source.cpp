#include <iostream>
#include <fstream>
#include <cmath>
#include <corecrt_math_defines.h>

using namespace std;

// Базовий клас Фігура
class Figura {
public:
    virtual void printInfo(ofstream& out) const = 0;
    virtual ~Figura() {}
};

// Клас Ромб
class Rhombus : public Figura {
private:
    double diagonal1, diagonal2;

public:
    Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}

    double getArea() const {
        return (diagonal1 * diagonal2) / 2;
    }

    double getInscribedCircleRadius() const {
        return getArea() / (0.5 * (diagonal1 + diagonal2));
    }

    void printInfo(ofstream& out) const override {
        out << "Ромб:\n";
        out << "Діагональ 1: " << diagonal1 << "\n";
        out << "Діагональ 2: " << diagonal2 << "\n";
        out << "Площа: " << getArea() << "\n";
        out << "Радіус вписаного кола: " << getInscribedCircleRadius() << "\n\n";
    }
};

// Клас Коло
class Circle : public Figura {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const {
        return M_PI * radius * radius;
    }

    double getCircumference() const {
        return 2 * M_PI * radius;
    }

    void printInfo(ofstream& out) const override {
        out << "Коло:\n";
        out << "Радіус: " << radius << "\n";
        out << "Площа: " << getArea() << "\n";
        out << "Довжина кола: " << getCircumference() << "\n\n";
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // Створення об'єктів
    Rhombus rhombus(10.0, 8.0);  // приклад з діагоналями 10 і 8
    Circle circle(rhombus.getInscribedCircleRadius()); // Вписане коло в ромб

    // Вивід інформації у файл
    ofstream outFile("figures_info.txt");
    if (!outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    rhombus.printInfo(outFile);
    circle.printInfo(outFile);

    outFile.close();
    cout << "Інформацію записано у файл 'figures_info.txt'." << endl;

    return 0;
}
