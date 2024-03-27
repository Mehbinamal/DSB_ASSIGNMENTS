#include <iostream>
#include "Linkedlist.h"

template <class T>
class Node_Circular_Doubly {
    T data;
    Node_Circular_Doubly* next;
    Node_Circular_Doubly* prev;
public:
    Node_Circular_Doubly();
    Node_Circular_Doubly(T data);
    void set_data(T x);
    T get_data();
    void set_next(Node_Circular_Doubly* next);
    Node_Circular_Doubly* get_next();
    void set_prev(Node_Circular_Doubly* prev);
    Node_Circular_Doubly* get_prev();
};
template <class T>
class CircularDoublyLinkedList : public LinkedList<T>{
    Node_Circular_Doubly<T>* head;
public:
    CircularDoublyLinkedList();
    Node_Circular_Doubly<T>* get_head();
    void create_ll();
    void display_ll();
    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_after_key(T key, T item);
    void insert_before_key(T key, T item);
    void delete_from_front();
    void delete_from_end();
    void delete_key(T key);
};


