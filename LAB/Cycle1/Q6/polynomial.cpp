#include "polynomial.h"
using namespace std;

Node::Node() {
    this->exp = 0;
    this->coefficient = 0;
    this->link = nullptr;
}

Node::Node(int exp,int coeff) {
    this->exp = exp;
    this->coefficient = coeff;
    this->link = nullptr;
}


void Node::set_exp(int x) {
    this->exp = x;
}

int Node::get_exp() {
    return exp;
}

void Node::set_link(Node* link) {
    this->link = link;
}

Node* Node::get_link() {
    return link;
}

void Node::set_coefficient(int x) {
    this->coefficient = x;
}

int Node::get_coefficient() {
    return coefficient;
}

LinkedList::LinkedList() {
    head = new Node();
}

Node* LinkedList::get_head() {
    return head;
}

void LinkedList::create_ll() {
    Node* current = head;
    int num;
    std::cout << "No of Terms:";
    std::cin >> num;
    for (int i = 0; i < num; i++) {
        int x,y;
        cout << "Enter Exponent:";
        cin >> x;
        cout<<"Enter Coefficient:";
        cin>>y;
        Node* node = new Node(x,y);
        current->set_link(node);
        current = node;
    }
}

void LinkedList::display_ll() {
    Node* current = head->get_link();
    while (current != nullptr) {
        if(current->get_link() != nullptr) {
            cout << current->get_coefficient() << "X^" << current->get_exp() << "+";
        }
        else{
            cout << current->get_coefficient() << "X^" << current->get_exp();
        }
        current = current->get_link();
    }
    cout << endl;
}

LinkedList LinkedList::add_poly(LinkedList p, LinkedList q) {
    Node* P = p.get_head()->get_link();
    Node* Q = q.get_head()->get_link();
    LinkedList r;
    Node* current = r.get_head();
    while(P != nullptr && Q != nullptr){
        if(P->get_coefficient()>Q->get_exp()){
            Node* node = new Node(P->get_exp(),P->get_coefficient());
            current->set_link(node);
            current = node;
            P = P->get_link();
        }
        else if(P->get_coefficient()<Q->get_exp()){
            Node* node = new Node(Q->get_exp(),Q->get_coefficient());
            current->set_link(node);
            current = node;
            Q = Q->get_link();
        }
        else{
            Node* node =  new Node();
            node->set_coefficient(P->get_coefficient()+Q->get_coefficient());
            current->set_link(node);
            current = node;
            P = P->get_link();
            Q = Q->get_link();
        }
    }
    return r;
}

LinkedList LinkedList::multiplication(LinkedList p, LinkedList q){
    LinkedList result;
    LinkedList term;
    Node* Z = term.get_head();
    Node* P = p.get_head();
    while (P != NULL){
        Node* Q = q.get_head()->get_link();
        P = P->get_link();
        while(Q != NULL){
            Node* newnode =new Node;
            newnode->set_exp(P->get_exp() + Q->get_exp());
            newnode->set_coefficient(P->get_coefficient() * Q->get_coefficient());
            Z->set_link(newnode);
            Z = newnode;
            Q = Q->get_link();
        }
        result = add_poly(result,term);
    }
    return result;
}