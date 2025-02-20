#include <iostream>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main() {
    char ch;
    
    cout << "Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher): ";
    cin >> ch;
    
    etype pos;
    
    switch(ch) {
        case 'l':
        case 'L':
            pos = laborer;
            break;
        case 's':
        case 'S':
            pos = secretary;
            break;
        case 'm':
        case 'M':
            pos = manager;
            break;
        case 'a':
        case 'A':
            pos = accountant;
            break;
        case 'e':
        case 'E':
            pos = executive;
            break;
        case 'r':
        case 'R':
            pos = researcher;
            break;
        default:
            cout << "Неверная буква!" << endl;
            return 1;
    }
    
    cout << "Полное название должности: ";
    switch(pos) {
        case laborer:
            cout << "laborer";
            break;
        case secretary:
            cout << "secretary";
            break;
        case manager:
            cout << "manager";
            break;
        case accountant:
            cout << "accountant";
            break;
        case executive:
            cout << "executive";
            break;
        case researcher:
            cout << "researcher";
            break;
    }
    
    cout << endl;
    return 0;
}