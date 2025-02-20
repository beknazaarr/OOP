#include<iostream>
using namespace std;
float stok(float);
int main () {
    float ls, kg;
    cout<<"\nВведите вес в фунтах: ";
    cin>>ls;
    kg=stok (ls);
    cout << "Вес в килограммах равен " << kg << endl;
    return 0;
}

float stok(float pounds) {
    float kilograms = 0.453592 * pounds;
    return kilograms;
}