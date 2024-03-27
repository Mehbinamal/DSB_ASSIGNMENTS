#include"Stack.h"
template<class T>
Stack<T>::Stack(){
	top=-1;
	size=100;
}
template<class T>
Stack<T>::Stack(int s){
    top=-1;
    size=s;
}
template<class T>
bool Stack<T>::isEmpty(){
	if(top==-1){
		return true;
	}
	return false;
}
template<class T>
bool Stack<T>::isFull(){
	if(top==size-1){
		return true;
	}
	return false;
}
template<class T>
void Stack<T>::push(T key){
	if(isFull()!=true){
		top+=1;
		S[top]=key;
	}
    overflow();
}
template<class T>
void Stack<T>::display(){
	int i;
	for(i=top;i>=0;i--){
		cout<<S[i]<<" ";
	}
	cout<<endl;
}
template<class T>
void Stack<T>::pop(){
	if(isEmpty()!=true){
		top=top-1;
	}
	underflow();
}
template<class T>
T Stack<T>::peek(){
	if(isEmpty()!=true){
		return S[top];
	}
	else{
		cout<<"Stack is empty \n";
		return -1;
	}
}
template<class T>
float Stack<T>::status(){
	return (float((top+1))/(size))*100;
}

template<class T>
void Stack<T>::underflow() {
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    }
}

template<class T>
void Stack<T>::overflow() {
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    }
}
