#include<iostream>
using namespace std;
void starline(char, int);
int main () {

char full;
int null;
cout<<"Введите символ:";
cin>>full;
cout<<"Введите число повторений символа:";
cin>>null;
starline(full, null);
return 0;
}
void starline (char ch,int  n) {

    for (int h=0; h<n; h++)
    cout<<ch;
    cout<<endl;
}
