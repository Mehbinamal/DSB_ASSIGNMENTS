#include "compairing.h"
int main() {
    Vector v;
    Complex c; 
    cout << "Enter the components of the vector:" << endl;
    cin >> v;
    cout << "Enter the components of the complex number:" << endl;
    cin >> c;
    if (v > c) {
        cout << "Magnitude of vector is greater than magnitude of complex number" << endl;
    } 
    else if (v < c) {
        cout << "Magnitude of vector is less than magnitude of complex number" << endl;
    } 
    else {
        cout << "Magnitudes of vector and complex number are equal" << endl;
    }
    return 0;
}
