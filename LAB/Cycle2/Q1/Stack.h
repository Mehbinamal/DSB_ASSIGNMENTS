#include<iostream>
#include<ostream>
using namespace std;
template<class T>
class Stack{
	T S[100];
	int top;
	int size;
	public:
		Stack();
        Stack(int s);
		bool isEmpty();
		bool isFull();
		void push(T key);
		void pop();
		T peek();
		float status();
		void display();
        void underflow();
        void overflow();
};

