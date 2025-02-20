#include <iostream>
using namespace std;

struct phone {
    int number1;
    int number2;
    int number3;
};
    
struct phone2 {
    int found1;
    int found2;
    int found3;
};
    
    int main () {
        
        phone2 phone2;
            cout<<"Введите код города, номер станции и номер абонента:"<<endl;
            cin>>phone2.found1>>phone2.found2>>phone2.found3;
            cout<<"Ваш номер "<<"("<<phone2.found1<<") "<<phone2.found2<<"-"<<phone2.found3<<endl;
            
        phone phone={212,767,8900};
        cout<<"МОй номер "<<"("<<phone.number1<<") "<<phone.number2<<"-"<<phone.number3<<endl;
        
    return 0;
}