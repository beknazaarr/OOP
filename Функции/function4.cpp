#include <iostream>
#include <cmath>

using namespace std;

struct Distance {
    int feet;
    float inches;
};

float circarea(float radius) {
    return M_PI * radius * radius;
}

double power(double n, int p = 2) {
    return pow(n, p);
}

void zeroSmaller(int &a, int &b) {
    if (a < b) {
        a = 0;
    } else {
        b = 0;
    }
}

Distance maxDistance(Distance d1, Distance d2) {
    float total1 = d1.feet * 12 + d1.inches;
    float total2 = d2.feet * 12 + d2.inches;
    return (total1 > total2) ? d1 : d2;
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
    cout << "Введите степень (по умолчанию 2): ";
    if (cin.peek() == '\n') {
        cout << "Результат: " << power(n) << endl;
    } else {
        cin >> p;
        cout << "Результат: " << power(n, p) << endl;
    }
    
    int x, y;
    cout << "Введите два числа: ";
    cin >> x >> y;
    zeroSmaller(x, y);
    cout << "Результат: " << x << " " << y << endl;
    
    Distance d1, d2;
    cout << "Введите первую длину (футы и дюймы): ";
    cin >> d1.feet >> d1.inches;
    cout << "Введите вторую длину (футы и дюймы): ";
    cin >> d2.feet >> d2.inches;
    Distance maxD = maxDistance(d1, d2);
    cout << "Наибольшая длина: " << maxD.feet << " футов " << maxD.inches << " дюймов" << endl;
    
    return 0;
}
