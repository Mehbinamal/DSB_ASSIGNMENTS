#include "Array.cpp"

int main(){

	Array<int>Array_h;
	cout<<"rotate Array Left"<<endl;
	cout<<"----------------"<<endl;
	Array_h.rotate_array_left();
	cout<<Array_h;

	Array<int>Array_i;
	cout<<"rotate Array Right"<<endl;
	cout<<"----------------"<<endl;
	Array_i.rotate_array_right();
	cout<<Array_i;

	Array<int>Array_j;
	Array_j.distinct_elements();

	Array<int>Array_k;
	Array_k.frequency_table();

	return 0;
}