#include <iostream>
#include <iomanip>   // ��� ���������������� ������
#include <string>    // ��� ������ �� ��������
#include <sstream>   // ��� ��������� �������� ������
#include <cstdlib>   // ��� exit()
using namespace std;

class bMoney {
private:
    long double amount; // �������� �����

    // ����������� ������ ������� "$1,234.56" � �����
    long double stringToLongDouble(const string& moneyStr) {
        string numStr;
        for (char ch : moneyStr) {
            if (isdigit(ch) || ch == '.' || ch == '-') {
                numStr += ch;
            }
        }
        return stold(numStr);
    }

    // ����������� ����� � ������ ������� "$1,234.56"
    string longDoubleToString(long double value) const {
        ostringstream oss;
        oss << fixed << setprecision(2) << value;
        string str = oss.str();

        // ��������� �������
        int pos = str.find('.');
        for (int i = pos - 3; i > 0; i -= 3) {
            str.insert(i, ",");
        }

        return "$" + str;
    }

public:
    // ������������
    explicit bMoney(long double amt = 0.0) : amount(amt) {}
    explicit bMoney(const string& moneyStr) : amount(stringToLongDouble(moneyStr)) {}

    // ���������� ����������
    bMoney operator+(const bMoney& other) const {
        return bMoney(amount + other.amount);
    }

    bMoney operator-(const bMoney& other) const {
        return bMoney(amount - other.amount);
    }

    bMoney operator*(long double factor) const {
        return bMoney(amount * factor);
    }

    long double operator/(const bMoney& other) const {
        if (other.amount == 0) {
            cout << "������: ������� �� ����!" << endl;
            exit(1);
        }
        return amount / other.amount;
    }

    bMoney operator/(long double divisor) const {
        if (divisor == 0) {
            cout << "������: ������� �� ����!" << endl;
            exit(1);
        }
        return bMoney(amount / divisor);
    }

    // �����
    void show() const {
        cout << longDoubleToString(amount);
    }

    // ����
    void getMoney() {
        string moneyStr;
        cout << "������� �������� ����� (������: $1,234.56): ";
        cin >> moneyStr;
        amount = stringToLongDouble(moneyStr);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    while (true) {
        bMoney b1, b2, result;
        long double num;
        char choice;

        cout << "\n������� ������ �����:\n";
        b1.getMoney();
        cout << "������� ������ �����:\n";
        b2.getMoney();
        cout << "������� ����� � ��������� ������:\n";
        cin >> num;

        // ����������
        result = b1 + b2;
        cout << "�����: "; result.show(); cout << endl;

        result = b1 - b2;
        cout << "��������: "; result.show(); cout << endl;

        result = b1 * num;
        cout << "���������: "; result.show(); cout << endl;

        cout << "������� ����� 1 �� ����� 2: " << b1 / b2 << endl;

        result = b1 / num;
        cout << "������� ����� 1 �� �����: "; result.show(); cout << endl;

        cout << "\n������ ���������� (y/n)? ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') break;
    }

    cout << "����� �� ���������.\n";
    return 0;
}
