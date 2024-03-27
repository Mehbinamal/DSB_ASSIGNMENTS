#include "Array.cpp"

int main(){
    char choice;
    int choice1;
    Array<int> array;
    do {
        cout<<"\t\tMenu"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1.Insertion at Beginning\n"
              "2.Insertion at end\n"
              "3.Insertion at a specified position.\n"
              "4.Deletion from Beginning\n"
              "5.Deletion from end\n"
              "6.Deletion from a specified position.\n"
              "7.Find the index of a given element\n"
              "8.Display"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice1;
        switch(choice1){
            case 1:
                cout<<"Inserting At Beginning"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"Enter Value :";
                int key;
                cin>>key;
                array.insert_at_beginning(key);
                break;
            case 2:
                cout<<"Inserting At End"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Enter Value :";
                cin>>key;
                array.insert_at_end(key);
                break;
            case 3:
                cout<<"Inserting At a Position"<<endl;
                cout<<"----------------"<<endl;
                array.insert_at_position();
                break;
            case 4:
                cout<<"delete At Beginning"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Element deleted"<<endl;
                array.delete_at_beginning();
                break;
            case 5:
                cout<<"delete At End"<<endl;
                cout<<"----------------"<<endl;
                cout<<"Element deleted"<<endl;
                array.delete_at_end();
                break;
            case 6:
                cout<<"delete At Position"<<endl;
                cout<<"----------------"<<endl;
                int pos;
                cout<<"Enter Position ("<<array.getLB()<<"-"<<array.getUB()<<"):";
                cin>>pos;
                array.delete_at_position(pos);
                cout<<"Element deleted"<<endl;
                break;
            case 7:
                cout<<"Index Of An element"<<endl;
                cout<<"-------------------"<<endl;
                cout<<"Enter Value to search:";
                cin>>key;
                if(array.binary_search(key) == -1){
                    cout<<"Element Not Present"<<endl;
                    break;
                }
                cout<<"Index :"<<array.binary_search(key)<<endl;
                break;
            case 8:
                cout<<array;
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