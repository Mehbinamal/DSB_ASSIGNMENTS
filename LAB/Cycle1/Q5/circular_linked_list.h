#include <iostream>
#include "Linkedlist.h"
template <class T>
class Node_Circular {
    T data;
    Node_Circular* link;
public:
    Node_Circular();
    Node_Circular(T data);
    void set_data(T x);
    T get_data();
    void set_link(Node_Circular* link);
    Node_Circular* get_link();
};

template <class T>
class CircularLinkedList : public LinkedList<T>{
    Node_Circular<T>* head;
    bool linear_search(T key);
    void swap(Node_Circular<T>* a, Node_Circular<T>* b);

public:
    CircularLinkedList();
    Node_Circular<T>* get_head();
    void create_ll();
    void display_ll();
    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_after_key(T key, T item);
    void insert_before_key(T key, T item);
    void delete_from_front();
    void delete_from_end();
    void delete_key(T key);
    //~CircularLinkedList();
};

