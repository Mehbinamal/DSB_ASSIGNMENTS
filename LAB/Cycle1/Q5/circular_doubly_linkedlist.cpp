#include "circular_doubly_linkedlist.h"

using namespace std;

template <class T>
Node_Circular_Doubly<T>::Node_Circular_Doubly() {
    this->data = NULL;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
Node_Circular_Doubly<T>::Node_Circular_Doubly(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template <class T>
void Node_Circular_Doubly<T>::set_data(T x) {
    this->data = x;
}

template <class T>
T Node_Circular_Doubly<T>::get_data() {
    return data;
}

template <class T>
void Node_Circular_Doubly<T>::set_next(Node_Circular_Doubly* next) {
    this->next = next;
}

template <class T>
Node_Circular_Doubly<T>* Node_Circular_Doubly<T>::get_next() {
    return next;
}

template <class T>
void Node_Circular_Doubly<T>::set_prev(Node_Circular_Doubly* prev) {
    this->prev = prev;
}

template <class T>
Node_Circular_Doubly<T>* Node_Circular_Doubly<T>::get_prev() {
    return prev;
}

template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList() {
    head = nullptr;
}

template <class T>
Node_Circular_Doubly<T>* CircularDoublyLinkedList<T>::get_head() {
    return head;
}

template <class T>
void CircularDoublyLinkedList<T>::create_ll() {
    Node_Circular_Doubly<T>* current = head;
    int num;
    std::cout << "No of Elements:";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        T x;
        cout << "Enter Data:";
        cin >> x;
        Node_Circular_Doubly<T>* node = new Node_Circular_Doubly<T>(x);
        if (current == nullptr) {
            head = node;
            current = head;
        } else {
            current->set_next(node);
            node->set_prev(current);
            current = node;
        }
    }
    if (current != nullptr) {
        current->set_next(head);
        head->set_prev(current);
    }
}

template <class T>
void CircularDoublyLinkedList<T>::display_ll() {
    Node_Circular_Doubly<T>* current = head;
    if (current == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    do {
        std::cout << current->get_data() << " ";
        current = current->get_next();
    } while (current != head);
    cout << endl;
}

template <class T>
void CircularDoublyLinkedList<T>::insert_at_beginning(T key) {
    Node_Circular_Doubly<T>* newnode = new Node_Circular_Doubly<T>(key);
    if (head == nullptr) {
        head = newnode;
        head->set_next(head);
        head->set_prev(head);
    } else {
        newnode->set_next(head);
        newnode->set_prev(head->get_prev());
        head->get_prev()->set_next(newnode);
        head->set_prev(newnode);
        head = newnode;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::insert_at_end(T key) {
    Node_Circular_Doubly<T>* newnode = new Node_Circular_Doubly<T>(key);
    if (head == nullptr) {
        head = newnode;
        head->set_next(head);
        head->set_prev(head);
    } else {
        newnode->set_next(head);
        newnode->set_prev(head->get_prev());
        head->get_prev()->set_next(newnode);
        head->set_prev(newnode);
    }
}

template <class T>
void CircularDoublyLinkedList<T>::insert_after_key(T key, T item) {
    Node_Circular_Doubly<T>* current = head;
    while (current != nullptr && current->get_data() != key) {
        current = current->get_next();
        if (current == head) {
            cout << "Key not found." << endl;
            return;
        }
    }
    Node_Circular_Doubly<T>* newnode = new Node_Circular_Doubly<T>(item);
    newnode->set_next(current->get_next());
    newnode->set_prev(current);
    current->get_next()->set_prev(newnode);
    current->set_next(newnode);
}

template <class T>
void CircularDoublyLinkedList<T>::insert_before_key(T key, T item) {
    Node_Circular_Doubly<T>* current = head;
    while (current != nullptr && current->get_data() != key) {
        current = current->get_next();
        if (current == head) {
            cout << "Key not found." << endl;
            return;
        }
    }
    Node_Circular_Doubly<T>* newnode = new Node_Circular_Doubly<T>(item);
    newnode->set_next(current);
    newnode->set_prev(current->get_prev());
    current->get_prev()->set_next(newnode);
    current->set_prev(newnode);
    if (current == head) {
        head = newnode;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::delete_from_front() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node_Circular_Doubly<T>* temp = head;
    head = head->get_next();
    head->set_prev(temp->get_prev());
    temp->get_prev()->set_next(head);
    delete temp;
}

template <class T>
void CircularDoublyLinkedList<T>::delete_from_end() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node_Circular_Doubly<T>* temp = head->get_prev();
    if (head->get_next() == head) {
        delete head;
        head = nullptr;
    } else {
        head->get_prev()->get_prev()->set_next(head);
        head->set_prev(head->get_prev()->get_prev());
        delete temp;
    }
}

template <class T>
void CircularDoublyLinkedList<T>::delete_key(T key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node_Circular_Doubly<T>* current = head;
    while (current != nullptr && current->get_data() != key) {
        current = current->get_next();
        if (current == head) {
            cout << "Key not found." << endl;
            return;
        }
    }
    if (current == head) {
        delete_from_front();
    } else if (current->get_next() == head) {
        delete_from_end();
    } else {
        current->get_prev()->set_next(current->get_next());
        current->get_next()->set_prev(current->get_prev());
        delete current;
    }
}

/*template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList() {
    Node_Circular_Doubly<T>* current = head;
    while (current != nullptr) {
        Node_Circular_Doubly<T>* temp = current;
        current = current->get_next();
        delete temp;
    }
    head = nullptr;
}
*/