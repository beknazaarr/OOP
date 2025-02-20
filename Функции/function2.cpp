#include <iostream>
#include <cmath>

using namespace std;

float circarea(float radius) {
    return M_PI * radius * radius;
}

double power(double n, int p = 2) {
    return pow(n, p);
}

int main() {
    float radius;
    cout << "Введите радиус: ";
    cin >> radius;
    cout << "Площадь круга: " << circarea(radius) << endl;
    
    double n;
    int p;
    cout << "Введите число: ";
    cin >> n;
    cout << "Введите степень: ";
    if (cin.peek() == '\n') {
        cout << "Результат: " << power(n) << endl;
    } else {
        cin >> p;
        cout << "Результат: " << power(n, p) << endl;
    }
    
    return 0;
}
