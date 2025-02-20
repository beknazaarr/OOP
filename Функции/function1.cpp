#include <iostream>
#include <cmath>

using namespace std;

float circarea(float radius) {
    return M_PI * radius * radius;
}

int main() {
    float radius;
    cout << "Введите радиус: ";
    cin >> radius;
    cout << "Площадь круга: " << circarea(radius) << endl;
    return 0;
}
