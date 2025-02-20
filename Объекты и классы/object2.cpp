#include <iostream>
#include <conio.h>

using namespace std;

class tollBooth {
private:
    unsigned int carCount;
    double revenue;
public:
    tollBooth() : carCount(0), revenue(0.0) {}
    void payingCar() {
        carCount++;
        revenue += 0.50;
    }
    void nopayCar() {
        carCount++;
    }
    void display() const {
        cout << "Общее количество автомобилей: " << carCount << endl;
        cout << "Общая выручка: $" << revenue << endl;
    }
};

int main() {
    tollBooth booth;
    char ch;
    cout << "Нажмите 'p' для платного проезда, 'n' для бесплатного проезда, 'Esc' для выхода.\n";
    while ((ch = _getch()) != 27) {
        if (ch == 'p') booth.payingCar();
        else if (ch == 'n') booth.nopayCar();
    }
    booth.display();
    return 0;
}
