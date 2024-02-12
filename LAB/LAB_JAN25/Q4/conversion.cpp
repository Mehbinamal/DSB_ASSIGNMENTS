#include "conversion.h"
int main(){
    cout<<"Metric to Imperial"<<endl;
    cout<<"------------------"<<endl;
    metric scl1;
    cin>>scl1;
    imperial scl2;
    scl2 = scl1;
    cout<<"Scale Object after Conversion \n"<<scl2;
    cout<<"imperial to metric"<<endl;
    cout<<"------------------"<<endl;
    imperial scl3;
    cin>>scl3;
    scl1 = scl3;
    cout<<"Scale Object after Conversion\n"<<scl1<<endl;
    return 0;
}