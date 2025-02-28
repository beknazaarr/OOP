#include <iostream>
using namespace std;
int main () {

int age[4];
for (int  i = 0; i < 4; i++)
{
    cout<<"Введите возраст:";
    cin>>age[i];
}
for ( int i = 0; i < 4; i++)

    cout<<"Вы ввели :"<< age[i]<<endl;
    
    return 0;
   
}