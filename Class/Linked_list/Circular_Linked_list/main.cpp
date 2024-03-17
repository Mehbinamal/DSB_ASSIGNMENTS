#include <iostream>
#include "circular_linked_list.cpp"
using namespace std;

int main() {
    int val1, val2, key, val3, val4, val5, val6;
    LinkedList<int> obj;
    obj.create_ll();
    cout << "Enter Value to be Inserted at beginning :";
    cin >> val1;
    obj.insert_at_beginning(val1);
    cout << "\nEnter Value to be Inserted at End :";
    cin >> val2;
    obj.insert_at_end(val2);
    cout << "\nEnter key & values needed to insert before and after:";
    cin >> key >> val3 >> val4;
    obj.insert_after_key(key, val3);
    obj.insert_before_key(key, val4);
    obj.display_ll();
    cout << "\nDeletion" << endl;
    obj.delete_from_front();
    obj.delete_from_end();
    obj.display_ll();
    cout << "\nEnter Value to be Deleted :";
    cin >> val5;
    obj.delete_key(val5);
    obj.display_ll();
    LinkedList<int> obj1;
    obj1.create_ll();
    cout << "\nConcatenation" << endl;
    LinkedList<int> obj3 = obj1.concatenation(obj, obj1);
    obj3.display_ll();
    LinkedList<int> obj4;
    obj4.create_ll();
    cout << "\nEnter Value to be Searched : ";
    cin >> val6;
    obj4.searching(val6);
    cout << "\nSorting" << endl;
    obj4.bubble_sort();
    obj4.display_ll();
    cout << "\nReverse Traversal";
    obj.reverse_traversal(obj.get_head());
    return 0;
}

