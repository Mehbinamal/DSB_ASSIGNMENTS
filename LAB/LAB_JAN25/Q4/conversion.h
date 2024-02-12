#include<iostream>
using namespace std;
class imperial;
class metric {
public:
    int m, cm;
    friend istream& operator>>(istream& is, metric& obj) {
        cout << "Enter the value in meters : ";
        is >> obj.m;
        cout << "Enter the value in Centimeters :";
        is >> obj.cm;
        return is;
    }
    friend ostream& operator<<(ostream& os, const metric& obj) {
        os << "The Value in Meter, Centimeter = " << obj.m << "'" << obj.cm << endl;
        return os;
    }
    void operator=(const imperial& obj);
};

class imperial {
public:
    int f, in;
    friend istream& operator>>(istream& is, imperial& obj) {
        cout << "Enter the value in Feet : ";
        is >> obj.f;
        cout << "Enter the value in Centi inches :";
        is >> obj.in;
        return is;
    }
    friend ostream& operator<<(ostream& os, const imperial& obj) {
        os << "The Value in Feet, Inches = " << obj.f << "'" << obj.in << endl;
        return os;
    }
    void operator=(const metric& obj);
};

void metric::operator=(const imperial& obj) {
    int temp;
    temp = obj.in + (obj.f * 12);
    m = temp / 39;
    cm = ((temp % 39) * 2.54);
}

void imperial::operator=(const metric& obj) {
    int temp;
    temp = obj.cm + (obj.m * 100);
    f = temp / 30;
    in = ((temp % 30) / 2.54);
}


