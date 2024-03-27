#include "circular_linked_list.h"
#include <iostream>
using namespace std;

template <class T>
Node_Circular<T>::Node_Circular() {
    this->data = NULL;
    this->link = nullptr;
}

template <class T>
Node_Circular<T>::Node_Circular(T data) {
    this->data = data;
    this->link = nullptr;
}

template <class T>
void Node_Circular<T>::set_data(T x) {
    this->data = x;
}

template <class T>
T Node_Circular<T>::get_data() {
    return data;
}

template <class T>
void Node_Circular<T>::set_link(Node_Circular* link) {
    this->link = link;
}

template <class T>
Node_Circular<T>* Node_Circular<T>::get_link() {
    return link;
}

template <class T>
CircularLinkedList<T>::CircularLinkedList() {
    head = new Node_Circular<T>();
}

template <class T>
Node_Circular<T>* CircularLinkedList<T>::get_head() {
    return head;
}

template <class T>
bool CircularLinkedList<T>::linear_search(T key) {
    Node_Circular<T>* current = head->get_link();
    do{
        if (current->get_data() == key) {
            return true;
        }
        current = current->get_link();
    }while (current != head->get_link());
    return false;
}

template <class T>
void CircularLinkedList<T>::swap(Node_Circular<T>* a, Node_Circular<T>* b) {
    T temp = a->get_data();
    a->set_data(b->get_data());
    b->set_data(temp);
}

template <class T>
void CircularLinkedList<T>::create_ll() {
    Node_Circular<T>* current = head;
    int num;
    std::cout << "No of Elements:";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        T x;
        cout << "Enter Data:";
        cin >> x;
        Node_Circular<T>* node = new Node_Circular<T>(x);
        current->set_link(node);
        current = node;
    }
    current->set_link(head->get_link());
}

template <class T>
void CircularLinkedList<T>::display_ll() {
    Node_Circular<T>* current = head->get_link();
    do{
        std::cout << current->get_data() << " ";
        current = current->get_link();
    }while (current != head->get_link());
    cout <<endl;
}

template <class T>
void CircularLinkedList<T>::insert_at_beginning(T key) {
    Node_Circular<T>* newnode = new Node_Circular<T>();
    newnode->set_data(key);
    newnode->set_link(head->get_link());
    head->set_link(newnode);
    Node_Circular<T>* p = newnode->get_link();
    do {
        p = p->get_link();
    } while (p->get_link()!=head->get_link());
    p->set_link(newnode);
}

template <class T>
void CircularLinkedList<T>::insert_at_end(T key) {
    Node_Circular<T>* p = head;
    do{
        p = p->get_link();
    }while (p->get_link() != head->get_link());
    Node_Circular<T>* newnode = new Node_Circular<T>();
    newnode->set_data(key);
    p->set_link(newnode);
    newnode->set_link(head->get_link());
}

template <class T>
void CircularLinkedList<T>::insert_after_key(T key, T item) {
    Node_Circular<T>* p = head;
    do{
        p = p->get_link();
    }while (p != head && p->get_data() != key);
    Node_Circular<T>* q = p->get_link();
    Node_Circular<T>* newnode = new Node_Circular<T>(item);
    newnode->set_link(q);
    p->set_link(newnode);
}

template <class T>
void CircularLinkedList<T>::insert_before_key(T key, T item) {
    Node_Circular<T>* p = head;
    Node_Circular<T>* q = p->get_link();
    while (q->get_data() != key) {
        p = q;
        q = q->get_link();
    }
    Node_Circular<T>* newnode = new Node_Circular<T>(item);
    newnode->set_link(q);
    p->set_link(newnode);
}

template <class T>
void CircularLinkedList<T>::delete_from_front() {
    Node_Circular<T>* temp = head->get_link();
    head->set_link(temp->get_link());
    delete temp;
}

template <class T>
void CircularLinkedList<T>::delete_from_end() {
    Node_Circular<T>* p = head;
    Node_Circular<T>* q = p->get_link();
    while (q->get_link() != nullptr) {
        p = q;
        q = q->get_link();
    }
    p->set_link(nullptr);
    delete q;
}

template <class T>
void CircularLinkedList<T>::delete_key(T key) {
    Node_Circular<T>* p = head;
    Node_Circular<T>* q = p->get_link();
    while (q->get_data() != key) {
        p = q;
        q = q->get_link();
    }
    p->set_link(q->get_link());
    delete q;
}

/*template <class T>
CircularLinkedList<T>::~CircularLinkedList() {
    Node_Circular<T>* current = head;
    while (current != nullptr) {
        Node_Circular<T>* temp = current;
        current = current->get_link();
        delete temp;
    }
}
*/

