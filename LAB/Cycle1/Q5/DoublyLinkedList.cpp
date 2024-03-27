#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

template <class T>
NodeDouble<T>::NodeDouble() {
    this->data = NULL;
    this->lLink = nullptr;
    this->rLink = nullptr;
}

template <class T>
NodeDouble<T>::NodeDouble(T data) {
    this->data = data;
    this->lLink = nullptr;
    this->rLink = nullptr;
}

template <class T>
void NodeDouble<T>::set_data(T x) {
    this->data = x;
}

template <class T>
T NodeDouble<T>::get_data() {
    return data;
}

template <class T>
void NodeDouble<T>::set_llink(NodeDouble* link) {
    this->lLink = link;
}

template <class T>
NodeDouble<T>* NodeDouble<T>::get_llink() {
    return lLink;
}

template <class T>
void NodeDouble<T>::set_rlink(NodeDouble* link) {
    this->rLink = link;
}

template <class T>
NodeDouble<T>* NodeDouble<T>::get_rlink() {
    return rLink;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = new NodeDouble<T>();
}

template <class T>
NodeDouble<T>* DoublyLinkedList<T>::get_head() {
    return head;
}

template <class T>
void DoublyLinkedList<T>::create_ll() {
    NodeDouble<T>* current = head;
    int num;
    cout << "No of Elements:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        T x;
        cout << "Enter Data:";
        cin >> x;
        NodeDouble<T>* node = new NodeDouble<T>(x);
        current->set_rlink(node);
        node->set_llink(current);
        current = node;
    }
}

template <class T>
void DoublyLinkedList<T>::display_ll() {
    NodeDouble<T>* current = head->get_rlink();
    while (current != nullptr) {
        cout << current->get_data() << " ";
        current = current->get_rlink();
    }
    cout << endl;
}

template <class T>
void DoublyLinkedList<T>::insert_at_beginning(T key) {
    NodeDouble<T>* newnode = new NodeDouble<T>();
    newnode->set_data(key);
    newnode->set_rlink(head->get_rlink());
    head->set_rlink(newnode);
    newnode->set_llink(head);
    newnode->get_rlink()->set_llink(newnode);
}

template <class T>
void DoublyLinkedList<T>::insert_at_end(T key) {
    NodeDouble<T>* p = head;
    while (p->get_rlink() != nullptr) {
        p = p->get_rlink();
    }
    NodeDouble<T>* newnode = new NodeDouble<T>();
    newnode->set_data(key);
    p->set_rlink(newnode);
    newnode->set_llink(p);
}

template <class T>
void DoublyLinkedList<T>::insert_after_key(T key, T item) {
    NodeDouble<T>* p = head;
    while (p != nullptr && p->get_data() != key) {
        p = p->get_rlink();
    }
    try {
        if (p == nullptr) {
            throw runtime_error("Key Not Present");
        }
        NodeDouble<T> *q = p->get_rlink();
        NodeDouble<T> *newnode = new NodeDouble<T>(item);
        newnode->set_rlink(q);
        if (q != nullptr) {
            q->set_llink(newnode);
        }
        p->set_rlink(newnode);
        newnode->set_llink(p);
    }
    catch (const exception &e){
        cout<<"Exception :"<<e.what()<<endl;
    }
}

template <class T>
void DoublyLinkedList<T>::insert_before_key(T key, T item) {
    NodeDouble<T>* p = head->get_rlink();
    while (p != nullptr && p->get_data() != key) {
        p = p->get_rlink();
    }
    try {
        if (p == nullptr) {
            throw runtime_error("Key Not Present");
        }
        NodeDouble<T> *newnode = new NodeDouble<T>(item);
        newnode->set_rlink(p);
        newnode->set_llink(p->get_llink());
        if (p->get_llink() != nullptr) {
            p->get_llink()->set_rlink(newnode);
        }
        p->set_llink(newnode);
    }
    catch (const exception &e){
        cout<<"Exception :"<<e.what()<<endl;
    }
}


template <class T>
void DoublyLinkedList<T>::delete_from_front() {
    NodeDouble<T>* temp = head->get_rlink();
    head->set_rlink(temp->get_rlink());
    temp->get_rlink()->set_llink(head);
    delete temp;
}

template <class T>
void DoublyLinkedList<T>::delete_from_end() {
    NodeDouble<T>* p = head;
    NodeDouble<T>* q = p->get_rlink();
    while (q->get_rlink() != nullptr) {
        p = q;
        q = q->get_rlink();
    }
    p->set_rlink(nullptr);
    delete q;
}

template <class T>
void DoublyLinkedList<T>::delete_key(T key) {
    NodeDouble<T>* p = head;
    NodeDouble<T>* q = p->get_rlink();
    while (q != nullptr && q->get_data() != key) {
        p = q;
        q = q->get_rlink();
    }
    try {
        if (q == nullptr) {
            throw runtime_error("Key Not Present");
        }
        p->set_rlink(q->get_rlink());
        if (q->get_rlink() != nullptr) {
            q->get_rlink()->set_llink(p);
        }
        delete q;
    }
    catch (const exception &e){
        cout<<"Exception :"<<e.what()<<endl;
    }
}

/*template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeDouble<T>* current = head;
    while (current != nullptr) {
        NodeDouble<T>* temp = current;
        current = current->get_rlink();
        delete temp;
    }
}*/


