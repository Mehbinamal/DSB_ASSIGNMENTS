#include "polynomial.cpp"

using namespace std;
int main(){
    LinkedList a;
    a.create_ll();
    LinkedList b;
    b.create_ll();
    LinkedList c;
    c = c.multiplication(a,b);
    c.display_ll();
    return 0;
}
