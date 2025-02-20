#include <iostream>
using namespace std;

class Employee {
private:
    int empID;
    float salary;
public:
    void setData() {
        cout << "Введите номер сотрудника: ";
        cin >> empID;
        cout << "Введите оклад сотрудника: ";
        cin >> salary;
    }
    void display() const {
        cout << "Номер сотрудника: " << empID << ", Оклад: " << salary << endl;
    }
};

int main() {
    Employee emp1, emp2, emp3;
    
    cout << "Введите данные для первого сотрудника:\n";
    emp1.setData();
    
    cout << "Введите данные для второго сотрудника:\n";
    emp2.setData();
    
    cout << "Введите данные для третьего сотрудника:\n";
    emp3.setData();
    
    cout << "\nИнформация о сотрудниках:\n";
    emp1.display();
    emp2.display();
    emp3.display();
    
    return 0;
}