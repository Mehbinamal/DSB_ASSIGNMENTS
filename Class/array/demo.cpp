#include "Array.cpp"

int main(){
	int a[] = {1, 2, 3, 4};
	int b[] = {1,2,3,4,5,6,7,8,9};
	int c[] = {101,9,5,7,7,6,6,3,2,1};
	int d[] = {0,9,5,8,7,6,4,3,2,1};

	Array<int> myArray;
	cout<<"Inserting At End"<<endl;
	cout<<"----------------"<<endl;
	myArray.insert_at_end(50);
	cout<<myArray;

	Array<int> myiArray;
	cout<<"Inserting At Beginning"<<endl;
	cout<<"----------------"<<endl;
	myiArray.insert_at_beginning(2);
	cout<<myiArray;

	Array<int>myjArray;
	myjArray.insert_at_position();
	cout<<myjArray;
	

	Array<int>mykArray;
	cout<<"delete At End"<<endl;
	cout<<"----------------"<<endl;
	mykArray.delete_at_end();
	cout<<mykArray;

	Array<int>Array_a;
	Array_a.delete_at_beginning();
	cout<<"delete At Beginning"<<endl;
	cout<<"----------------"<<endl;
	cout<<Array_a;

	Array<int>Array_b;
	cout<<"Linear Search"<<endl;
	cout<<"----------------"<<endl;
	int Linear = Array_b.linear_search();
	cout<<Linear<<endl;

	Array<int>Array_c;
	cout<<"Binary Search"<<endl;
	cout<<"----------------"<<endl;
	cout<<"Enter Value to search:";
	int key;
	cin>>key;
	int binary = Array_c.binary_search(key);
	cout<<binary<<endl;

	Array<int>Array_d;
	cout<<"Selection sort"<<endl;
	cout<<"----------------"<<endl;
	Array_d.selection_sort();
	cout<<Array_d;

	Array<int>Array_e;
	cout<<"bubble sort"<<endl;
	cout<<"----------------"<<endl;
	Array_e.bubble_sort();
	cout<<Array_e;

	Array<int>Array_f;
	cout<<"insertion sort"<<endl;
	cout<<"----------------"<<endl;
	Array_f.insertion_sort();
	cout<<Array_f;

	Array<int>Array_g;
	cout<<"quick sort"<<endl;
	cout<<"----------------"<<endl;
	Array_g.quick_sort(Array_g.getLB(),Array_g.getUB());
	cout<<Array_g;

	Array<int>Array_l;
	cout<<"merge sort"<<endl;
	cout<<"----------------"<<endl;
	Array_l.merge_sort(Array_l.getLB(),Array_l.getUB());
	cout<<Array_l;

	Array<int>Array_h;
	cout<<"rotate Array Left"<<endl;
	cout<<"----------------"<<endl;
	Array_h.rotate_array_left();
	cout<<Array_h;

	Array<int>Array_i;
	cout<<"rotate Array Right"<<endl;
	cout<<"----------------"<<endl;
	Array_i.rotate_array_left();
	cout<<Array_i;

	Array<int>Array_j;
	Array_j.distinct_elements();

	Array<int>Array_k;
	Array_k.frequency_table();



	return 0;
}