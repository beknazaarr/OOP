#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "До обмена: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "После обмена: x = " << x << ", y = " << y << endl;
    return 0;
}
