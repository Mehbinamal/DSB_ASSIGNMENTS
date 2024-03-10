#include<iostream>
using namespace std;
class Node{
    int data;
    Node* link;
    public:
    Node(){
        this->data= NULL ;
        this->link= nullptr;
    }
    Node(int data){
        this->data=data;
        this->link= nullptr;
    }
    void set_data(int x){
        this->data=x;
    }
    int get_data(){
        return data;
    }
    void set_link(Node* link){
        this->link=link;
    }
    Node* get_link(){
        return link;
    }
};

class LinkedList{
    private:
    Node* head;

    bool liner_search(int key){
        Node* current =head->get_link();
        while(current!=NULL){
            if(current->get_data() == key){
                return true;
            }
            current = current->get_link();
        }
        return false;
    }

    void swap(Node* a,Node* b){
        int temp = a->get_data();
        a->set_data(b->get_data());
        b->set_data(temp);
    }

    public:
    LinkedList() {
        head = new Node();
    }
    Node* get_head(){
        return head;
    }
    void create_ll(){
        Node* current = head;
        int num;
        cout<<"No of Elements:";
        cin>>num;
        for(int i=0;i<num;i++)
        {
            int x;
            cout<<"Enter Data:";
            cin>>x;
            Node* node =  new Node(x);
            current->set_link(node);
            current = node;
        }

    }
    void display_ll(){
        Node* current = head->get_link();
        while (current != NULL) {
            cout << current->get_data() << " ";
            current = current->get_link();
        }
        cout << endl;
    }

    void insert_at_beginning(int key){
        Node* newnode = new Node();
        newnode->set_data(key);
        newnode->set_link(head->get_link());
        head->set_link(newnode);

    }

    void insert_at_end(int key){
        Node* p = head;
        while (p->get_link() != nullptr){
            p = p->get_link();
        }
        Node* newnode = new Node();
        newnode ->set_data(key);
        p->set_link(newnode);
    }

    void insert_after_key(int key,int item){
        Node* p = head;
        while(p != NULL && p->get_data() != key){
            p = p->get_link();
        }
        Node* q = p->get_link();
        Node* newnode = new Node(item);
        newnode->set_link(q);
        p->set_link(newnode);
    }

    void insert_before_key(int key,int item){
        Node* p = head;
        Node* q = p->get_link();
        while(q->get_data() != key){
            p = q;
            q = q->get_link();
        }
        Node* newnode = new Node(item);
        newnode->set_link(q);
        p->set_link(newnode);
    }

    void delete_from_front(){
        Node* temp = head->get_link();
        head->set_link(temp->get_link());
        delete temp;
    }

    void delete_from_end(){
        Node* p = head;
        Node* q = p->get_link();
        while(q->get_link() != NULL){
            p = q;
            q = q->get_link();
        }
        p->set_link(nullptr);
        delete q;
    }

    void delete_key(int key){
        Node* p = head;
        Node* q = p->get_link();
        while(q->get_data() != key){
            p = q;
            q = q->get_link();
        }
        p->set_link(q->get_link());
        delete q;
    }

    LinkedList concatenation(LinkedList l1, LinkedList l2) {
        LinkedList l3;
        Node* current = l3.head;
        Node* p = l1.head->get_link();
        while (p != nullptr) {
            Node* newnode = new Node(p->get_data());
            current->set_link(newnode);
            current = current->get_link();
            p = p->get_link();
        }
        Node* q = l2.head->get_link();
        while (q != nullptr) {
            Node* newnode = new Node(q->get_data());
            current->set_link(newnode);
            current = current->get_link();
            q = q->get_link();
        }
        return l3;
    }

    void searching(int key){
        bool result = liner_search(key);
        if(result){
            cout<<"Element Found"<<endl;
        }
        else{
            cout<<"Element Not Found"<<endl;
        }
    }

    void reversing(){
        Node* prev = NULL;
        Node* next = NULL;
        Node* current = head->get_link();
        while(current!=NULL){
            next = current->get_link();
            current->set_link(prev);
            prev = current;
            current = next;
        }
        head->set_link(prev);
    }

    void reverse_traversal(Node* node){
        if (node == head){
            node = node->get_link();
        }
        if (node == NULL){
            return;
        }
        reverse_traversal(node->get_link());
        cout<<node->get_data()<<" ";
    }

    int get_count(){
        int count =0;
        Node* current = head->get_link();
        while(current != NULL){
            current = current->get_link();
            count++;
        }
        return count;
    }

    void bubble_sort(){
        bool swapped;
        do{
            swapped = false;
            Node* current = head;
            Node* next = nullptr;
            while (current->get_link()!=next){
                if(current->get_data()>current->get_link()->get_data()){
                    swap(current,current->get_link());
                    swapped = true;
                }
                current = current->get_link();
            }
            next = current;
        } while (swapped);
    }


    ~LinkedList(){
        Node* current = head;
        while(current != nullptr){
            Node* temp = current;
            current = current->get_link();
            delete temp;
        }
    }


};

int main(){
    int val1,val2,key,val3,val4,val5,val6;
    LinkedList obj;
    obj.create_ll();
    cout<<"Enter Value to be Inserted at beginning :";
    cin>>val1;
    obj.insert_at_beginning(val1);
    cout<<"\nEnter Value to be Inserted at End :";
    cin>>val2;
    obj.insert_at_end(val2);
    cout<<"\nEnter key & values needed to insert before and after:";
    cin>>key>>val3>>val4;
    obj.insert_after_key(key,val3);
    obj.insert_before_key(key,val4);
    obj.display_ll();
    cout<<"\nDeletion"<<endl;
    obj.delete_from_front();
    obj.delete_from_end();
    obj.display_ll();
    cout<<"\nEnter Value to be Deleted :";
    cin>>val5;
    obj.delete_key(val5);
    obj.display_ll();
    LinkedList obj1;
    obj1.create_ll();
    cout<<"\nConcatenation"<<endl;
    LinkedList obj3 = obj1.concatenation(obj,obj1);
    obj3.display_ll();
    LinkedList obj4;
    obj4.create_ll();
    cout<<"\nEnter Value to be Searched : ";
    cin>>val6;
    obj4.searching(val6);
    cout<<"\nSorting"<<endl;
    obj4.bubble_sort();
    obj4.display_ll();
    cout<<"\nReverse Traversal";
    obj.reverse_traversal(obj.get_head());
    return 0;
}
