#include <iostream>
#include <ostream>
template <class T>
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
};

template <class T>
class LinkedList {
    Node<T>* head;

public:
    LinkedList();
    Node<T>* get_head();
    void create_ll();
    void display_ll();
    void insert_at_beginning(T key);
    void insert_at_end(T key);
    void insert_after_key(T key, T item);
    void insert_before_key(T key, T item);
    void delete_from_front();
    void delete_from_end();
    void delete_key(T key);
    template <class U>
    friend std::ostream& operator<<(std::ostream&, LinkedList<U>);
    //~LinkedList();
};

