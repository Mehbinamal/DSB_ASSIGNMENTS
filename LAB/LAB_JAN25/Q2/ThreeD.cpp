#include "threeD.h"
int main(){
    Vector v1,v2,v3,v5;
    int v4;
    cout << "Vector 1"<<endl;
    cout <<"---------"<<endl;
    cin>>v1;
    cout << "Vector 2"<<endl;
    cout <<"---------"<<endl;
    cin>>v2;
    v3 = v1 + v2;
    v4 = v1*v2;//dot product
    v5 = v1^v2;//cross product
    cout << "Results"<<endl;
    cout <<"--------"<<endl;
    cout<<"The sum of the vectors is: "<<v3<<endl;
    cout<<"The Dot product of vectors is :"<<v4<<endl;
    cout<<"The Cross product of vectors is :"<<v5<<endl;
    return 0;
}