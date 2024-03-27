#include <iostream>

template<class T>
class LinkedList{
public:
    virtual void create_ll() = 0;
    virtual void display_ll() = 0;
    virtual void insert_at_beginning(T key) = 0;
    virtual void insert_at_end(T key) = 0;
    virtual void insert_after_key(T key, T item) = 0;
    virtual void insert_before_key(T key, T item) = 0;
    virtual void delete_from_front() = 0;
    virtual void delete_from_end() = 0;
    virtual void delete_key(T key) = 0;
};