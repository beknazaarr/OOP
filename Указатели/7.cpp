#include <iostream>
#include <cstring>
#include <clocale>
using namespace std;

class person {
private:
    char name[40];
    float salary;
public:
    void setData() {
        cout << "������� ���: ";
        cin >> name;
        cout << "������� ��������: ";
        while (!(cin >> salary) || salary < 0) {
            cout << "������! ������� ������������� �����: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    void printData() {
        cout << "���: " << name << ", ��������: " << salary << endl;
    }
    float getSalary() {
        return salary;
    }
};

void salsort(person** pp, int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
            if ((*(pp + j))->getSalary() > (*(pp + k))->getSalary()) {
                person* temp = *(pp + j);
                *(pp + j) = *(pp + k);
                *(pp + k) = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int SIZE = 3;
    person* persPtr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        persPtr[i] = new person;
        cout << "���� ������ ��� �������� " << i + 1 << ":\n";
        persPtr[i]->setData();
    }

    cout << "\n�� ����������:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    salsort(persPtr, SIZE);

    cout << "\n����� ���������� �� ��������:\n";
    for (int i = 0; i < SIZE; i++) {
        persPtr[i]->printData();
    }

    for (int i = 0; i < SIZE; i++) {
        delete persPtr[i];
    }

    return 0;
}