#include "linked_list.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node() {
    this->data = NULL;
    this->link = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->link = nullptr;
}

template <class T>
void Node<T>::set_data(T x) {
    this->data = x;
}

template <class T>
T Node<T>::get_data() {
    return data;
}

template <class T>
void Node<T>::set_link(Node* link) {
    this->link = link;
}

template <class T>
Node<T>* Node<T>::get_link() {
    return link;
}

template <class T>
LinkedList<T>::LinkedList() {
    head = new Node<T>();
}

template <class T>
Node<T>* LinkedList<T>::get_head() {
    return head;
}

template <class T>
void LinkedList<T>::create_ll() {
    Node<T>* current = head;
    int num;
    std::cout << "No of Elements:";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        T x;
        std::cout << "Enter Data:";
        std::cin >> x;
        Node<T>* node = new Node<T>(x);
        current->set_link(node);
        current = node;
    }
}

template <class T>
void LinkedList<T>::display_ll() {
    Node<T>* current = head->get_link();
    while (current != nullptr) {
        std::cout << current->get_data() << " ";
        current = current->get_link();
    }
    std::cout << std::endl;
}

template <class T>
void LinkedList<T>::insert_at_beginning(T key) {
    Node<T>* newnode = new Node<T>();
    newnode->set_data(key);
    newnode->set_link(head->get_link());
    head->set_link(newnode);
}

template <class T>
void LinkedList<T>::insert_at_end(T key) {
    Node<T>* p = head;
    while (p->get_link() != nullptr) {
        p = p->get_link();
    }
    Node<T>* newnode = new Node<T>();
    newnode->set_data(key);
    p->set_link(newnode);
}

template <class T>
void LinkedList<T>::insert_after_key(T key, T item) {
    Node<T>* p = head;
    while (p != nullptr && p->get_data() != key) {
        p = p->get_link();
    }
    Node<T>* q = p->get_link();
    Node<T>* newnode = new Node<T>(item);
    newnode->set_link(q);
    p->set_link(newnode);
}

template <class T>
void LinkedList<T>::insert_before_key(T key, T item) {
    Node<T>* p = head;
    Node<T>* q = p->get_link();
    while (q->get_data() != key) {
        p = q;
        q = q->get_link();
    }
    Node<T>* newnode = new Node<T>(item);
    newnode->set_link(q);
    p->set_link(newnode);
}

template <class T>
void LinkedList<T>::delete_from_front() {
    Node<T>* temp = head->get_link();
    head->set_link(temp->get_link());
    delete temp;
}

template <class T>
void LinkedList<T>::delete_from_end() {
    Node<T>* p = head;
    Node<T>* q = p->get_link();
    while (q->get_link() != nullptr) {
        p = q;
        q = q->get_link();
    }
    p->set_link(nullptr);
    delete q;
}

template <class T>
void LinkedList<T>::delete_key(T key) {
    Node<T>* p = head;
    Node<T>* q = p->get_link();
    while (q->get_data() != key) {
        p = q;
        q = q->get_link();
    }
    p->set_link(q->get_link());
    delete q;
}

/*template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->get_link();
        delete temp;
    }
}*/

template <class U>
ostream& operator << (ostream& os,LinkedList<U> M){
    Node<U>* current = M.head->get_link();
    while (current != nullptr) {
        std::cout << current->get_data() << " ";
        current = current->get_link();
    }
    std::cout << std::endl;
    return os;
}
