#include <iostream>
#include <clocale>
using namespace std;

int compstr(char* s1, char* s2) {
    while (*s1 && *s2) {
        if (*s1 < *s2) return -1;
        if (*s1 > *s2) return 1;
        s1++;
        s2++;
    }
    if (*s1) return 1;
    if (*s2) return -1;
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");

    char str1[] = "������";
    char str2[] = "�����";
    char str3[] = "������";

    cout << "��������� \"" << str1 << "\" � \"" << str2 << "\": " << compstr(str1, str2) << endl;
    cout << "��������� \"" << str2 << "\" � \"" << str1 << "\": " << compstr(str2, str1) << endl;
    cout << "��������� \"" << str1 << "\" � \"" << str3 << "\": " << compstr(str1, str3) << endl;

    return 0;
}