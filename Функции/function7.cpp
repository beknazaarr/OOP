#include <iostream>
#include <cmath>

using namespace std;

struct Distance {
    int feet;
    float inches;
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};

float circarea(float radius) {
    return M_PI * radius * radius;
}

double power(double n, int p = 2) {
    return pow(n, p);
}

char power(char n, int p = 2) {
    return static_cast<char>(pow(n, p));
}

int power(int n, int p = 2) {
    return static_cast<int>(pow(n, p));
}

long power(long n, int p = 2) {
    return static_cast<long>(pow(n, p));
}

float power(float n, int p = 2) {
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

long time_to_secs(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

Time secs_to_time(long total_seconds) {
    Time t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    t.seconds = total_seconds % 60;
    return t;
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
    cin >> p;
    cout << "Результат: " << power(n, p) << endl;
    
    char c;
    cout << "Введите символ (char): ";
    cin >> c;
    cout << "Результат: " << power(c, p) << endl;
    
    int i;
    cout << "Введите число (int): ";
    cin >> i;
    cout << "Результат: " << power(i, p) << endl;
    
    long l;
    cout << "Введите число (long): ";
    cin >> l;
    cout << "Результат: " << power(l, p) << endl;
    
    float f;
    cout << "Введите число (float): ";
    cin >> f;
    cout << "Результат: " << power(f, p) << endl;
    
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
    
    Time t1, t2;
    cout << "Введите первое время (часы, минуты, секунды): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;
    cout << "Введите второе время (часы, минуты, секунды): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;
    
    long total_secs = time_to_secs(t1) + time_to_secs(t2);
    Time result_time = secs_to_time(total_secs);
    
    cout << "Сумма времен: " << result_time.hours << " ч " << result_time.minutes << " мин " << result_time.seconds << " сек" << endl;
    
    return 0;
}
