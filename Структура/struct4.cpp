#include <iostream>
using namespace std;

 struct employee {
     int id;
     float dollar;
 };
 
 int main () {
   employee sot1, sot2, sot3;
  
  cout<<"Введите id первого сотрудника и пособию в виде доллара:"<<endl;
  cin>>sot1.id>>sot1.dollar;
  
  cout<<"Введите id второго сотрудника и пособию в виде доллара:"<<endl;
  cin>>sot2.id>>sot2.dollar;
  
  cout<<"Введите id третьего сотрудника и пособию в виде доллара:"<<endl;
  cin>>sot3.id>>sot3.dollar;
  
  cout<<"ID первого сотрудника "<<sot1.id<<" и пособие в виде доллара составляет:"<<sot1.dollar<<endl;
    cout<<"ID второго сотрудника "<<sot2.id<<" и пособие в виде доллара составляет:"<<sot2.dollar<<endl;
  cout<<"ID третьего сотрудника "<<sot3.id<<" и пособие в виде доллара составляет:"<<sot3.dollar<<endl;

     return 0;
 }
 