#include <iostream>
using namespace std;

 struct date {
     int day;
     int month;
     int year;
 };
 
 int main () {
     date dater;
     
      cout<<"Введите свое дата рождения. Сначало день потом месяц и год:"<<endl;
     cin>>dater.day>>dater.month>>dater.year;
     
     if (dater.day >= 1 && dater.day <= 31 &&
        dater.month >= 1 && dater.month <= 12 &&
        dater.year >= 1990 && dater.year <= 2024) {

     
     cout<<dater.day<<"/"<<dater.month<<"/"<<dater.year;
     }
     else {
        cout << "Ошибка: введены некорректные данные!" << endl;
    }
     return 0;
 }