#include<iostream>
using namespace std;
float stok(float);
int main () {
    float ls, kg;
    cout<<"\nВведите вес в фунтах: ";
    cin>>ls;
    cout << "Вес в килограммах равен " << stok(ls) << endl;
    return 0;
}

float stok(float pounds) {
return 0.453592 * pounds;
}