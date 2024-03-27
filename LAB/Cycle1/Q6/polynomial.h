#include <iostream>
#include <ostream>
class Node {
    int exp;
    int coefficient;
    Node* link;
public:
    Node();
    Node(int exp,int coeff);
    void set_exp(int x);
    int get_exp();
    void set_coefficient(int x);
    int get_coefficient();
    void set_link(Node* link);
    Node* get_link();
};

class LinkedList {
    Node* head;

public:
    LinkedList();
    Node* get_head();
    void create_ll();
    void display_ll();
    LinkedList add_poly(LinkedList p,LinkedList q);
    LinkedList multiplication(LinkedList p,LinkedList q);
    //~LinkedList();
};

