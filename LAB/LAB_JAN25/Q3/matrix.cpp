#include"matrix.h"
int main() {
    Matrix m1,m2,m3,m4;
    cin >> m1;
    cin >> m2;
    cout<<"Matrix Addition:"<<endl;
    m3 = m1+m2;
    cout <<m3;
    cout<<"Matrix Multiplication:"<<endl;
    m4 = m1*m2;
    cout << m4;
    return 0;
}