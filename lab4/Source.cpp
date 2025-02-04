#include <iostream>
#include <fstream>
#include <cmath>
#include <corecrt_math_defines.h>

using namespace std;

// ������� ���� Գ����
class Figura {
public:
    virtual void printInfo(ofstream& out) const = 0;
    virtual ~Figura() {}
};

// ���� ����
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
        out << "����:\n";
        out << "ĳ������� 1: " << diagonal1 << "\n";
        out << "ĳ������� 2: " << diagonal2 << "\n";
        out << "�����: " << getArea() << "\n";
        out << "����� ��������� ����: " << getInscribedCircleRadius() << "\n\n";
    }
};

// ���� ����
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
        out << "����:\n";
        out << "�����: " << radius << "\n";
        out << "�����: " << getArea() << "\n";
        out << "������� ����: " << getCircumference() << "\n\n";
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // ��������� ��'����
    Rhombus rhombus(10.0, 8.0);  // ������� � ���������� 10 � 8
    Circle circle(rhombus.getInscribedCircleRadius()); // ������� ���� � ����

    // ���� ���������� � ����
    ofstream outFile("figures_info.txt");
    if (!outFile) {
        cerr << "������� �������� �����!" << endl;
        return 1;
    }

    rhombus.printInfo(outFile);
    circle.printInfo(outFile);

    outFile.close();
    cout << "���������� �������� � ���� 'figures_info.txt'." << endl;

    return 0;
}
