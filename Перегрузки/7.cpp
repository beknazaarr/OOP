#include <iostream>
#include <cstdlib>  // ��� abs() � exit()
using namespace std;

class Fraction {
private:
    int numerator, denominator;

    // ����� ��� ���������� ����������� ������ �������� (���)
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return abs(a); // ���������� ������������� ��������
    }

public:
    // �����������
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "������: ����������� �� ����� ���� 0!" << endl;
            exit(1);
        }
        simplify(); // ����� ��������� �����
    }

    // ����� ��� ���������� �����
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
        if (denominator < 0) { // ���� ������ � ���������
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // ���������� ��������� ��������
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    // ���������� ��������� ���������
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    // ���������� ��������� ���������
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // ���������� ��������� �������
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // ���������� ��������� ��������� ==
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    // ���������� ��������� ��������� !=
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // ����� �����
    void display() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Fraction frac1, frac2, result;
    char oper;
    int num, den;

    cout << "������� ������� ����������� (+, -, *, /). ������� 0/1 ��� ������.\n";

    while (true) {
        // ���� ������ �����
        cout << "\n������� ������ ����� (��������� ����������� ����� ������): ";
        cin >> num >> den;
        if (num == 0 && den == 1) break; // ������� ������
        frac1 = Fraction(num, den);

        // ���� ���������
        cout << "������� �������� (+, -, *, /): ";
        cin >> oper;

        // ���� ������ �����
        cout << "������� ������ ����� (��������� ����������� ����� ������): ";
        cin >> num >> den;
        if (num == 0 && den == 1) break; // ������� ������
        frac2 = Fraction(num, den);

        // ����������
        switch (oper) {
        case '+': result = frac1 + frac2; break;
        case '-': result = frac1 - frac2; break;
        case '*': result = frac1 * frac2; break;
        case '/': result = frac1 / frac2; break;
        default:
            cout << "������: ������������ ��������!" << endl;
            continue;
        }

        // ����� ����������
        cout << "���������: ";
        result.display();
        cout << endl;
    }

    cout << "����� �� ���������.\n";
    return 0;
}
