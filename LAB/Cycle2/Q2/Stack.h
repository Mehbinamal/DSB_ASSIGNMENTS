#ifndef Q2_STACK_H
#define Q2_STACK_H
#include <iostream>
#include "/home/oem/Desktop/LabDsb/cycle1/LinkedList/linked_list.cpp"
/*template <class T>
class Node {
    T data;
    Node* link;
    public:
        Node();
        Node(T data);
        void set_data(T x);
        T get_data();
        void set_link(Node* link);
        Node* get_link();
};*/

template <class T>
class Stack {
    Node<T>* top;
    int size;
    public:
        Stack();
        Stack(int size);
        bool isEmpty();
        bool isFull();
        void push(T key);
        void pop();
        void display();
        
};




#endif //Q2_STACK_H
