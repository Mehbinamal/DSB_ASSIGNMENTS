#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node() {
    this->data = NULL;
    this->lLink = nullptr;
    this->rLink = nullptr;
}

template <class T>
Node<T>::Node(T data) {
    this->data = data;
    this->lLink = nullptr;
    this->rLink = nullptr;
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
void Node<T>::set_llink(Node* link) {
    this->lLink = link;
}

template <class T>
Node<T>* Node<T>::get_llink() {
    return lLink;
}

template <class T>
void Node<T>::set_rlink(Node* link) {
    this->rLink = link;
}

template <class T>
Node<T>* Node<T>::get_rlink() {
    return rLink;
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
bool LinkedList<T>::linear_search(T key) {
    Node<T>* current = head->get_rlink();
    while (current != nullptr) {
        if (current->get_data() == key) {
            return true;
        }
        current = current->get_rlink();
    }
    return false;
}

template <class T>
void LinkedList<T>::swap(Node<T>* a, Node<T>* b) {
    T temp = a->get_data();
    a->set_data(b->get_data());
    b->set_data(temp);
}

template <class T>
void LinkedList<T>::create_ll() {
    Node<T>* current = head;
    int num;
    cout << "No of Elements:";
    cin >> num;
    for (int i = 0; i < num; i++) {
        T x;
        cout << "Enter Data:";
        cin >> x;
        Node<T>* node = new Node<T>(x);
        current->set_rlink(node);
        node->set_llink(current);
        current = node;
    }
}

template <class T>
void LinkedList<T>::display_ll() {
    Node<T>* current = head->get_rlink();
    while (current != nullptr) {
        cout << current->get_data() << " ";
        current = current->get_rlink();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::insert_at_beginning(T key) {
    Node<T>* newnode = new Node<T>();
    newnode->set_data(key);
    newnode->set_rlink(head->get_rlink());
    head->set_rlink(newnode);
    newnode->set_llink(head);
    newnode->get_rlink()->set_llink(newnode);
}

template <class T>
void LinkedList<T>::insert_at_end(T key) {
    Node<T>* p = head;
    while (p->get_rlink() != nullptr) {
        p = p->get_rlink();
    }
    Node<T>* newnode = new Node<T>();
    newnode->set_data(key);
    p->set_rlink(newnode);
    newnode->set_llink(p);
}

template <class T>
void LinkedList<T>::insert_after_key(T key, T item) {
    Node<T>* p = head;
    while (p != nullptr && p->get_data() != key) {
        p = p->get_rlink();
    }
    try {
        if (p == nullptr) {
            throw runtime_error("Key Not Present");
        }
        Node<T> *q = p->get_rlink();
        Node<T> *newnode = new Node<T>(item);
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
void LinkedList<T>::insert_before_key(T key, T item) {
    Node<T>* p = head->get_rlink();
    while (p != nullptr && p->get_data() != key) {
        p = p->get_rlink();
    }
    try {
        if (p == nullptr) {
            throw runtime_error("Key Not Present");
        }
        Node<T> *newnode = new Node<T>(item);
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
void LinkedList<T>::delete_from_front() {
    Node<T>* temp = head->get_rlink();
    head->set_rlink(temp->get_rlink());
    temp->get_rlink()->set_llink(head);
    delete temp;
}

template <class T>
void LinkedList<T>::delete_from_end() {
    Node<T>* p = head;
    Node<T>* q = p->get_rlink();
    while (q->get_rlink() != nullptr) {
        p = q;
        q = q->get_rlink();
    }
    p->set_rlink(nullptr);
    delete q;
}

template <class T>
void LinkedList<T>::delete_key(T key) {
    Node<T>* p = head;
    Node<T>* q = p->get_rlink();
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


template <class T>
void LinkedList<T>::concatenation(LinkedList<T> l1) {
    Node<T>* p = head->get_rlink();
    while (p->get_rlink() != nullptr) {
        p = p->get_rlink();
    }
    p->set_rlink(l1.get_head()->get_rlink());
    l1.get_head()->get_rlink()->set_llink(p);
}

template <class T>
void LinkedList<T>::searching(T key) {
    bool result = linear_search(key);
    if (result) {
        cout << "Element Found" << endl;
    } else {
        cout << "Element Not Found" << endl;
    }
}

template <class T>
void LinkedList<T>::reversing() {
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    Node<T>* current = head->get_rlink();
    while (current != nullptr) {
        next = current->get_rlink();
        current->set_rlink(prev);
        current->set_llink(next);
        prev = current;
        current = next;
    }
    head->set_link(prev);
}

template <class T>
void LinkedList<T>::reverse_traversal(Node<T>* node) {
    if (node == head) {
        node = node->get_rlink();
    }
    if (node == nullptr) {
        return;
    }
    reverse_traversal(node->get_rlink());
    cout << node->get_data() << " ";
}

template <class T>
int LinkedList<T>::get_count() {
    int count = 0;
    Node<T>* current = head->get_link();
    while (current != nullptr) {
        current = current->get_link();
        count++;
    }
    return count;
}

template <class T>
void LinkedList<T>::bubble_sort() {
    bool swapped;
    do {
        swapped = false;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current->get_rlink() != next) {
            if (current->get_data() > current->get_rlink()->get_data()) {
                swap(current, current->get_rlink());
                swapped = true;
            }
            current = current->get_rlink();
        }
        next = current;
    } while (swapped);
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->get_rlink();
        delete temp;
    }
}


