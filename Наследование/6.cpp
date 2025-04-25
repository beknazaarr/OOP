#include <iostream>
#include <cstdlib>  // ��� exit()
#include <locale>

using namespace std;

const int SIZE = 10; // ����������� ������ ������� � safearray

// ������� �����: ����������� ���������� ������
class safearray {
protected:
    int arr[SIZE];  // ������ �������������� �������
public:
    int& operator[](int index) {
        if (index < 0 || index >= SIZE) {
            cout << "������! ������ " << index << " ������� �� ������� ������� (0 - " << SIZE - 1 << ").\n";
            exit(1);
        }
        return arr[index];
    }
};

// ����������� �����: ������ � ������������� ���������
class safehilo : public safearray {
private:
    int lower; // ������ �������
    int upper; // ������� �������
    int* dynamicArray; // ������������ ������

public:
    // ����������� � ����������������� ���������
    safehilo(int low, int up) : lower(low), upper(up) {
        if (upper < lower) {
            cout << "������! ������� ������� ������ ������.\n";
            exit(1);
        }
        dynamicArray = new int[upper - lower + 1]; // ������� ������ ������� �������
    }

    // ���������� ����������� ������
    ~safehilo() {
        delete[] dynamicArray;
    }

    // ���������������� �������� []
    int& operator[](int index) {
        if (index < lower || index > upper) {
            cout << "������! ������ " << index << " ������� �� ������� ������� (" << lower << " - " << upper << ").\n";
            exit(1);
        }
        return dynamicArray[index - lower]; // ����������� ������ � ���������
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "������� ������ safehilo � ��������� -5 �� 5.\n";
    safehilo arr(-5, 5);

    // ��������� ������ ����������
    for (int i = -5; i <= 5; i++)
        arr[i] = i * 10; // ������ ��������

    // ������� ��������
    cout << "���������� �������:\n";
    for (int i = -5; i <= 5; i++)
        cout << "arr[" << i << "] = " << arr[i] << endl;

    // ������� ������ �� �������
    cout << "\n��������� ���������� � arr[6]:\n";
    cout << arr[6]; // ������

    return 0;
}
 