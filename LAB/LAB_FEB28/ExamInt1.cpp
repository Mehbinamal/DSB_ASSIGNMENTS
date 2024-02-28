#include <iostream>
#include "ExamInt1.h"
using namespace std;
Array::Array(int LB,int UB) {
    this->LB=LB;
    this->UB = UB;
    if(LB>UB){
        cout<<"Invalid Bound ";
        exit(0);
    }
    else {
        cout << "Enter element : ";
        for (int i = LB; i <= UB; i++) {
            cin >> A[i];
        }
    }
}


void Array::replaceElement(int key,int x) {
    bool found = false;
    for(int i =LB;i<=UB;i++){
        if(key == A[i]){
            A[i] = x;
            found = true;
            break;
        }
    }
    if(!found){
        cout<<"Element Not Present";
    }
}

void Array::reversePrinting(int lb, int ub) {
    if (lb > ub) {
        return;
    }
    cout << A[ub] << " ";
    reversePrinting(lb, ub - 1);
}

int Array::matchingSubstring(string str,string sub) {
    int pos=0;
    int count =0;
    while(pos<= str.length()- sub.length()){
        int j = 0;
        while (str[pos+j]==sub[j] & sub[j] != '\0')
            j++;
        if(sub[j] == '\0')
            count++;
        pos = pos+1;
    }
    return count;
}
void Array::display() {
    cout<<"Array : ";
    for (int j=LB;j<=UB;j++){
        cout<<A[j]<<" ";
    }
}
