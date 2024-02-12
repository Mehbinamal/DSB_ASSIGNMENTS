#include<iostream>
using namespace std;
class Vector{
    public:
        int x,y,z;
        friend istream& operator>>(istream& is,Vector& obj){
            cout<<"Enter X cordinate:";
            is >> obj.x;
            cout<<"Enter 'Y' cordinate:";
            is >> obj.y;
            cout<<"Enter 'Z' cordinate:";
            is >> obj.z;
            return is;
        }
        friend ostream& operator<<(ostream& os,Vector& obj){
            os <<"<"<< obj.x<<","<<obj.y<<","<<obj.z<<">";
            return os;
        }
        friend Vector operator+(Vector a,Vector b);
        friend Vector operator/(Vector a,Vector b);
        friend Vector operator^(Vector a,Vector b);
        
};
Vector operator+(Vector a,Vector b){
    Vector result;
    result.x = a.x+b.x;
    result.y = a.y+b.y;
    result.z = a.z+b.z;
    return result;
}
int operator*(Vector a,Vector b){
    Vector result;
    result.x = a.x*b.x;
    result.y = a.y*b.y;
    result.z = a.z*b.z;
    return result.x+result.y+result.z; 
}
Vector operator^(Vector a,Vector b){
    Vector result;
    result.x = (a.y*b.z)-(a.z*b.y);
    result.y = -((a.x*b.z)-(a.z*b.x));
    result.z = (a.x*b.y)-(a.y*b.x);
    return result; 
}
