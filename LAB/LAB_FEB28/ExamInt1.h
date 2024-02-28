#ifndef EXAMINT1_H
#define EXAMINT1_H
using namespace std;
class Array {
public:
    Array(int LB,int UB);
    int A[100];
    int LB;
    int UB;
    void replaceElement(int key,int x);
    void reversePrinting(int LB,int UB);
    int matchingSubstring(string str,string sub);
    void display();
};
#endif


