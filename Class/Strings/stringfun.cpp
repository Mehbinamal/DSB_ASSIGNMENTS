#include "Strings.h"

Strings::Strings() {
    S[0] = '\0';
}

int Strings::length(const char* Str) {
    int i = 0;
    while (Str[i] != '\0') {
        i++;
    }
    return i;
}

int Strings::comparing(const char* S1, const char* S2) {
    int i = 0;
    while (S1[i] == S2[i] && S1[i] != '\0' && S2[i] != '\0') {
        i++;
    }
    return S1[i] - S2[i];
}
char* Strings::concatenation(const char* s1,const char* s2){
    int l1 = length(s1);
    int l2 = length(s2);
    char* s3 = new char[l1+l2+1];
    for (int i=0;i<l1;i++){
        s3[i] = s1[i];
    }
    for (int i=0;i<l2;i++){
        s3[l1+i] = s2[i];
    }
    s3[l1+l2+1] = '\0';
    return s3;
}
void Strings::reverse(){
    char temp;
    int i=0;
    int j= length(S);
    j=j-1;
    while(i<j){
        temp=S[i];
        S[i]=S[j];
        S[j]=temp;
        i++;
        j--;
    }
}
char* Strings::subString(int start,int len){
    char*T = new char[len+1];
    for (int i=0;i<len;i++)
        T[i] = S[start+i];
    return T;
}

int Strings::matchSubString(char T[]){
    int pos=0;
    while(pos<= length(S)- length(T)){
        int j = 0;
        while (S[pos+j]==T[j] & T[j] != '\0')
            j++;
        if(T[j] == '\0')
            return pos;
        pos = pos+1;
    }
    return -1;
}