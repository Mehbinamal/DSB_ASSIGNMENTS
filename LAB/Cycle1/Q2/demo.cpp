#include "Array.cpp"

int main(){
    char choice;
    int choice1;
    Array<int> array;
    do {
        cout<<"\t\tMenu"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1.Quick Sort\n"
              "2.Bubble sort\n"
              "3.Insertion Sort\n"
              "4.Merge Sort\n"
              "5.Selection Sort\n"
              "6.Binary Search\n"
              "7.Linear Search\n"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice1;
        switch(choice1){
            case 1:
                cout<<"Quick Sort"<<endl;
                cout<<"-----------"<<endl;
                array.quick_sort(array.getLB(),array.getUB());
                cout<<array;
                break;
            case 2:
                cout<<"Bubble Sort"<<endl;
                cout<<"-----------"<<endl;
                array.bubble_sort();
                cout<<array;
                break;
            case 3:
                cout<<"Insertion Sort"<<endl;
                cout<<"--------------"<<endl;
                array.insertion_sort();
                cout<<array;
                break;
            case 4:
                cout<<"Merge Sort"<<endl;
                cout<<"-----------"<<endl;
                array.merge_sort(array.getLB(),array.getUB());
                cout<<array;
                break;
            case 5:
                cout<<"Selection Sort"<<endl;
                cout<<"--------------"<<endl;
                array.selection_sort();
                cout<<array;
                break;
            case 6:
                cout<<"Linear Search"<<endl;
                cout<<"-------------"<<endl;
                cout<<"Index :"<<array.linear_search()<<endl;
                break;
            case 7:
                cout<<"Index Of An element"<<endl;
                cout<<"-------------------"<<endl;
                cout<<"Enter Value to search:";
                int key;
                cin>>key;
                int index;
                index = array.binary_search(key);
                if(index == -1){
                    cout<<"Element Not Present"<<endl;
                    break;
                }
                cout<<"Index :"<<index<<endl;
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