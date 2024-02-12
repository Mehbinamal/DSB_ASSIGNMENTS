#include<iostream>
using namespace std;
class Complex{
    public:
        float real,image;
        Complex(){
            image = 0;
            real = 0;
        }
        Complex(float real_,float image_){
            this->image = image_;
            this->real = real_;
        }
        Complex operator+(Complex second){
            Complex result;
            result.real = this->real + second.real;
            result.image = this->image+second.image;
            return result;    
        }
        friend Complex operator*(Complex a,Complex b){
            Complex result;
            result.real = (a.real*b.real)-(a.image*b.image);
            result.image = (a.real*b.image)+(a.image*b.real);
            return result;
        }
        friend ostream& operator<<(ostream& osp,Complex& obj){
            osp << "Complex number : "<<obj.real<<"+"<<obj.image<<"i"<<endl;
            return osp;
        }
        friend istream& operator>>(istream& is, Complex& obj){
            cout<<"Enter Real part:";
            is >> obj.real;
            cout<<"Enter imaginary part:";
            is >> obj.image;
            return is;
        }
};
