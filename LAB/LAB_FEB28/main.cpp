#include <iostream>
#include "ExamInt1.cpp"
using namespace std;

int main() {
    int lb,ub,key,x;
    cout<<"Enter LB :";
    cin>>lb;
    cout<<"Enter UB :";
    cin>>ub;
    Array a(lb,ub);
    a.display();
    cout<<"\nEnter Element to be Replaced:";
    cin>>key;
    cout<<"\nEnter Element : ";
    cin>>x;
    a.replaceElement(key,x);
    a.display();
    cout<<"\nReversing\n----------"<<endl;
    a.reversePrinting(lb,ub);
    string s,b;
    cout<<"\nEnter Main String : ";
    cin>>s;
    cout<<"\nEnter substring : ";
    cin>>b;
    cout<<"\nNumber of matches"<<a.matchingSubstring(s,b)<<endl;
    return 0;
}
