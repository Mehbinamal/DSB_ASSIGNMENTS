#include <iostream>
#include <cstring>
#include "stringfun.cpp"
using namespace std;

int main() {
    Strings a;
    char s1[] = "Computer";
    char s2[] = " Science";
    char T[] ="ter";
    strcpy(a.S, s1);
    cout << "Length: " << a.length(a.S) << endl;
    cout << "Compare: " << a.comparing("AAAAAAA", "AAAAAAA") << endl;
    char* s3 =a.concatenation(s1,s2);
    cout << "Concatenation: "<<s3<<endl;
    delete[] s3;
    char* s4 = a.subString(2,3);
    cout << "SubString: "<<s4<<endl;
    delete[] s4;
    cout << "Matching : "<<a.matchSubString(T)<<endl;
    a.reverse();
    cout<<a.S<<endl;
    return 0;
}
