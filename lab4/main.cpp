#include <iostream>
#include <fstream>
#include "Square.h"
#include "Circle.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // ��������� ��'����
    Square square(10.0); // ������� � �������� 10
    Circle circle(square.getInscribedCircleRadius()); // ������� ����

    // ���� ���������� � ����
    ofstream outFile("figures_info.txt");
    if (!outFile) {
        cerr << "������� �������� �����!" << endl;
        return 1;
    }

    square.printInfo(outFile);
    circle.printInfo(outFile);

    outFile.close();
    cout << "���������� �������� � ���� 'figures_info.txt'." << endl;

    return 0;
}
