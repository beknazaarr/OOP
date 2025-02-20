#include <iostream>
using namespace std;

class Int {
private:
    int value;
public:
    Int() : value(0) {}
    Int(int v) : value(v) {}
    void setZero() { value = 0; }
    void setValue(int v) { value = v; }
    void display() const { cout << "Значение: " << value << endl; }
    Int add(const Int& other) const { return Int(value + other.value); }
};

int main() {
    Int num1(5), num2(10), num3;
    num3 = num1.add(num2);
    num3.display();
    return 0;
}
