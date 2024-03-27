#include <iostream>
#include "linked_list.cpp"
using namespace std;

int main() {
    char choice;
    int choice1;
    LinkedList<int> list;
    list.create_ll();
    do {
        cout<<"\t\tMenu"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1.Insertion at Beginning\n"
              "2.Insertion at end\n"
              "3.Insertion at a specified position.\n"
              "4.Deletion from Beginning\n"
              "5.Deletion from end\n"
              "6.Deletion from a specified position.\n"
              "7.Display"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice1;
        switch(choice1){
            case 1:
                cout<<"Inserting At Beginning"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"Enter Value :";
                int key;
                cin>>key;
                list.insert_at_beginning(key);
                break;
            case 2:
                cout<<"Inserting At End"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Enter Value :";
                cin>>key;
                list.insert_at_end(key);
                break;
            case 3:
                int item;
                char choice2;
                cout<<"Inserting At a Position"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Enter Value :";
                cin>>key;
                cout<<"Enter Value to be Inserted";
                cin>>item;
                cout<<"1.Before\n2.After"<<endl;
                cout<<"Enter your choice : ";
                cin>>choice2;
                if(choice2 == 1){
                    list.insert_before_key(key,item);
                }
                else if (choice2 == 2){
                    list.insert_after_key(key,item);
                }
                else{
                    cout<<"Invalid Entry";
                }
                break;
            case 4:
                cout<<"delete At Beginning"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Element deleted"<<endl;
                list.delete_from_front();
                break;
            case 5:
                cout<<"delete At End"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Element deleted"<<endl;
                list.delete_from_end();
                break;
            case 6:
                cout<<"delete At Position"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Enter Value :";
                cin>>key;
                list.delete_key(key);
                cout<<"Element deleted"<<endl;
                break;
            case 7:
                cout<<list;
                break;
            default:
                cout<<"Invalid Entry"<<endl;
                break;
        }
        cout<<"Do you Want to continue(y/n) : ";
        cin>>choice;
    }while(choice == 'y');
    return 0;
}
