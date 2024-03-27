#include <iostream>
#include "Linkedlist.h"
template <class T>
class NodeDouble {
    T data;
    NodeDouble* lLink;
    NodeDouble* rLink;
public:
    NodeDouble();
    NodeDouble(T data);
    void set_data(T x);
    T get_data();
    void set_llink(NodeDouble* link);
    NodeDouble* get_llink();
    void set_rlink(NodeDouble* link);
    NodeDouble* get_rlink();
};

template <class T>
class DoublyLinkedList : public LinkedList<T>{
    NodeDouble<T>* head;
public:
    DoublyLinkedList();
    NodeDouble<T>* get_head();
    void create_ll();
    void display_ll();
    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_after_key(T key, T item);
    void insert_before_key(T key, T item);
    void delete_from_front();
    void delete_from_end();
    void delete_key(T key);
    //~DoublyLinkedList();
};

