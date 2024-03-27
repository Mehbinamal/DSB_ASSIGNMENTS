#include<iostream>
#include<ostream>

using namespace std;
template <class T>
class Array{
	int LB,UB;
	T A[100];
  public:
  	Array();
  	Array(int,int,T[]);
	void setLB(int x);
	int getLB();
	void setUB(int x);
	int getUB();
  	void insert_at_end(T key);
	void insert_at_beginning(T key);
	void insert_at_position();
	void delete_at_end();
	void delete_at_beginning();
    void delete_at_position(int pos);
	int linear_search();
	int binary_search(T key);
	void selection_sort();
	void bubble_sort();
	void insertion_sort();
	int partition(int LB, int UB);
	void quick_sort(int LB, int UB);
	void swap(T &a,T &b);
	void merge(int LB, int mid, int UB);
	void merge_sort(int LB, int UB);
	void rotate_array_left();
	void rotate_array_right();
	void distinct_elements();
	void frequency_table();
 	template <class U>
  	friend ostream& operator<<(ostream&, Array<U>);
};
