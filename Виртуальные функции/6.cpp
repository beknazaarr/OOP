#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class bMoney {
private:
    long double money;
public:
    bMoney() : money(0.0) {}
    bMoney(long double m) : money(m) {}

    void getmoney() {
        string input;
        cout << "������� ����� (��������, $1,234.56): ";
        cin >> input;
        money = 0.0;
        for (char c : input) {
            if (isdigit(c)) money = money * 10 + (c - '0');
            else if (c == '.') break;
        }
        size_t pos = input.find('.');
        if (pos != string::npos) {
            string cents = input.substr(pos + 1);
            long double fraction = 0.0;
            for (char c : cents) {
                if (isdigit(c)) fraction = fraction * 10 + (c - '0');
            }
            while (fraction >= 1) fraction /= 10;
            money += fraction;
        }
    }

    void putmoney() const {
        cout << fixed << setprecision(2) << "$" << money;
    }

    bMoney operator+(const bMoney& m) const {
        return bMoney(money + m.money);
    }

    bMoney operator-(const bMoney& m) const {
        return bMoney(money - m.money);
    }

    bMoney operator*(const bMoney& m) const {
        return bMoney(money * m.money);
    }

    bMoney operator/(const bMoney& m) const {
        return bMoney(money / m.money);
    }

    bMoney operator*(long double factor) const {
        return bMoney(money * factor);
    }

    friend bMoney operator*(long double factor, const bMoney& m) {
        return bMoney(factor * m.money);
    }

    friend bMoney operator/(long double number, const bMoney& m) {
        return bMoney(number / m.money);
    }
};

int main() {
    bMoney m1, m2, result;
    long double number;

    cout << "������� ������ �����:\n";
    m1.getmoney();
    cout << "������� ������ �����:\n";
    m2.getmoney();
    cout << "������� ����� � ��������� �������: ";
    cin >> number;

    cout << "\n���������� ��������:\n";
    result = m1 + m2;
    cout << "��������: "; result.putmoney(); cout << endl;

    result = m1 - m2;
    cout << "���������: "; result.putmoney(); cout << endl;

    result = m1 * m2;
    cout << "��������� (bMoney * bMoney): "; result.putmoney(); cout << endl;

    result = m1 / m2;
    cout << "������� (bMoney / bMoney): "; result.putmoney(); cout << endl;

    result = m1 * number;
    cout << "��������� (bMoney * �����): "; result.putmoney(); cout << endl;

    result = number * m1;
    cout << "��������� (����� * bMoney): "; result.putmoney(); cout << endl;

    result = number / m1;
    cout << "������� (����� / bMoney): "; result.putmoney(); cout << endl;

    return 0;
}