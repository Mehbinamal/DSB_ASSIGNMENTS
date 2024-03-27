#include "Stack.h"


#include <iostream>
using namespace std;

template<class T>
Stack<T>::Stack(int size) {
    top = new Node<T>;
    this->size = size;
}

template<class T>
Stack<T>::Stack() {
    top = new Node<T>;
    size = 0;
}

template<class T>
bool Stack<T>::isEmpty() {
    if(top==NULL){
        return true;
    }
    return false;
}

template<class T>
bool Stack<T>::isFull() {
    if(top->get_link()== nullptr){
        return true;
    }
    return false;
}

template<class T>
void Stack<T>::push(T key) {
    if (isFull()) {
        cout<<"STACK OVERFLOW";
        return;
    }
    Node<T>* newNode = new Node(key);
    newNode->set_link(top);
    top = newNode;
    size++;
}

template<class T>
void Stack<T>::pop() {
    if (isEmpty()) {
        std::cerr << "STACK UNDERFLOW";
        return ;
    }
    Node<T>* temp = top;
    int poppedData = top->data;
    top = top->next;
    delete temp;
    size--;
    cout<<poppedData<<endl;
}

template<class T>
void Stack<T>::display(){
    Node<T>* current = top;
    while (current != NULL) {
        cout << current->get_data() << " ";
        current = current->get_link();
    }
    cout << endl;
}