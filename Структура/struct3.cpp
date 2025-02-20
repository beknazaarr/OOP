#include <iostream>
using namespace std;

struct Distance {
  int feet;
  double inches;
};

struct Volume {
  int length;
  int width;
  int heigth;
};

int main () { 
   Distance length, width, heigth;
   
   cout<<"Введите длину (футы и дюмы)"<<endl;
   cin>>length.feet>>length.inches;
   
   cout<<"Введите ширину (футы и дюмы)"<<endl;
   cin>>width.feet>>width.inches;
   
   cout<<"Введите высоту (футы и дюмы)"<<endl;
   cin>>heigth.feet>>heigth.inches;

   float volume=(length.feet+length.inches/12)*(width.feet+width.inches/12)*(heigth.feet+heigth.inches/12);

   cout << "Объем помещения: " << volume << " кубических футов" << endl;
 
 return 0;
}