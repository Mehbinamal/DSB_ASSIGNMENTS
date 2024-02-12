#include "complex.h"
int main(){
    Complex c1,c2,c3,c4;
    cin >> c1;
    cin >> c2;
    c3 = c1 + c2;
    cout<<"The sum is : ";
    cout << c3;
    c4 = c1*c2;
    cout<<"The Product is : ";
    cout << c4;
    return 0;
}
