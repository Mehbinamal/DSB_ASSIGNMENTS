#include<iostream>
#include<cmath>
using namespace std;

class Complex {
public:
    double real, image;
    friend istream& operator>>(istream& is, Complex& obj);
    float magnitude() const {
        return sqrt(real * real + image * image);
    }
};
class Vector {
public:
    int x, y, z;
    friend istream& operator>>(istream& is, Vector& obj);
    float magnitude() const {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    bool operator>(const Complex& c) const {
        float mag_v = this->magnitude();
        float mag_c = c.magnitude();
        return mag_v > mag_c;
    }
    bool operator<(const Complex& c) const {
        float mag_v = this->magnitude();
        float mag_c = c.magnitude();
        return mag_v < mag_c;
    }
    bool operator==(const Complex& c) const {
        float mag_v = this->magnitude();
        float mag_c = c.magnitude();
        return mag_v == mag_c;
    }
};

istream& operator>>(istream& is, Vector& obj) {
    cout << "Enter X coordinate:";
    is >> obj.x;
    cout << "Enter Y coordinate:";
    is >> obj.y;
    cout << "Enter Z coordinate:";
    is >> obj.z;
    return is;
}


istream& operator>>(istream& is, Complex& obj) {
    cout << "Enter Real part:";
    is >> obj.real;
    cout << "Enter Imaginary part:";
    is >> obj.image;
    return is;
}
