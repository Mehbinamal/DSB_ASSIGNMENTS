#include "Array.cpp"

int main(){
	int a[] = {1, 2, 3, 4};
	int b[] = {1,2,3,4,5,6,7,8,9};
	int c[] = {0,9,5,8,7,6,4,3,2,1};
	int d[] = {0,9,5,8,7,6,4,3,2,1};

	Array<int> myArray(1,5,a);
	myArray.insert_at_end(3);
	myArray.insert_at_beginning(1,5,a,99);
	myArray.delete_at_end();
	myArray.delete_at_beginning(1,5,a);
	cout<<myArray;
	
	Array<float> myfArray;
	myfArray.insert_at_end(3.5);
	myfArray.insert_at_end(5.5);
	myfArray.insert_at_end(6.3);
	cout<<myfArray;

	Array<int> myiArray(0,3,a);
	myiArray.insert_at_position(0,3,a,10,2);
	cout<<myiArray;

	Array<int>myjArray(0,9,b);
	int linear = myjArray.linear_search(0,9,b,5);
	int binary = myjArray.binary_search(0,9,b,8);
	cout<<linear<<endl;
	cout<<binary<<endl;

	Array<int>mykArray(0,9,c);
	mykArray.selection_sort(0,9,c);
	cout<<mykArray;

	Array<int>mymArray(0,9,d);
	mymArray.bubble_sort(0,9,d);
	cout<<mymArray;

	return 0;
}