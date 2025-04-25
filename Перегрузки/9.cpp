#include <iostream>
#include <cstdlib>  // ��� exit()
using namespace std;

const int SIZE = 100; // ������������� ������ �������

class safearray {
private:
    int arr[SIZE];   // ������ ������
    int lower, upper; // ������ � ������� �������

public:
    // �����������: ������ ������� �������
    safearray(int low, int high) {
        if (high - low + 1 > SIZE) {
            cout << "������: �������� ������������ ������ �������!" << endl;
            exit(1);
        }
        lower = low;
        upper = high;
    }

    // ������������� �������� []
    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "������: ����� �� ������� �������!" << endl;
            exit(1);
        }
        return arr[index - lower]; // �������������� �������
    }

    // ����� ������� (��� ��������)
    void display() const {
        for (int i = 0; i <= upper - lower; i++) {
            cout << "arr[" << (i + lower) << "] = " << arr[i] << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    int low, high;
    cout << "������� ������ ������� ��������: ";
    cin >> low;
    cout << "������� ������� ������� ��������: ";
    cin >> high;

    safearray sa(low, high);

    // ��������� ������
    for (int i = low; i <= high; i++) {
        sa[i] = i * 10; // ������ ������ ������
    }

    // ������� ������
    sa.display();

    // ���� ������ �� ������� (���������������� ��� ��������)
    // cout << sa[high + 1] << endl; // ������

    return 0;
}
