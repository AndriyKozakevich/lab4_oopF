#include <iostream>
#include <fstream>
#include "Square.h"
#include "Circle.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    // Створення об'єктів
    Square square(10.0); // квадрат зі стороною 10
    Circle circle(square.getInscribedCircleRadius()); // Вписане коло

    // Вивід інформації у файл
    ofstream outFile("figures_info.txt");
    if (!outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    square.printInfo(outFile);
    circle.printInfo(outFile);

    outFile.close();
    cout << "Інформацію записано у файл 'figures_info.txt'." << endl;

    return 0;
}
