#include <iostream>
template <class T>
class Node {
    T data;
    Node* lLink;
    Node* rLink;
public:
    Node();
    Node(T data);
    void set_data(T x);
    T get_data();
    void set_llink(Node* link);
    Node* get_llink();
    void set_rlink(Node* link);
    Node* get_rlink();
};

template <class T>
class LinkedList {
    Node<T>* head;
    bool linear_search(T key);
    void swap(Node<T>* a, Node<T>* b);

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
    void concatenation(LinkedList<T> l1);
    void searching(T key);
    void reversing();
    void reverse_traversal(Node<T>* node);
    int get_count();
    void bubble_sort();
    ~LinkedList();
};

