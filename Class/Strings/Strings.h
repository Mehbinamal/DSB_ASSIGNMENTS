#include <iostream>
#include <cstring>
using namespace std;
class Strings{
public:
    Strings();
    char S[100];
    int length(const char* Str);
    int comparing(const char* S1,const char* S2);
    char* concatenation(const char* s1,const char* s2);
    void reverse();
    char* subString(int start,int len);
    int matchSubString(char T[]);
};

