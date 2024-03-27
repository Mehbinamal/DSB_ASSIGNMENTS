#include"Stack.cpp"
int main(){
    cout<<"Enter the Size of Stack :";
    int size;
    cin>>size;
	Stack<int> st(size);
    char choice='y';
    while(choice=='y'){
        cout<<"Enter Data :";
        int data;
        cin>>data;
        st.push(data);
        cout<<"Do you want to add more :";
        cin>>choice;
    }
    st.display();
    cout<<"Status :"<<st.status()<<"%"<<endl;
    cout<<"Top Element ::"<<st.peek()<<endl;
    choice = 'y';
    while(choice=='y'){
        cout<<"Do you want to PoP :";
        cin>>choice;
        if(choice == 'y'){
            st.pop();
        }
    }
    st.display();
    cout<<"Status :"<<"%"<<st.status();
    return 0;
}

