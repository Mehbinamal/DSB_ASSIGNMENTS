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
  	void insert_at_end(T key);
	void insert_at_beginning(int LB,int UB,T[],T key);
	void insert_at_position(int LB,int UB,T[],T key,int pos);
	void delete_at_end();
	void delete_at_beginning(int LB,int UB,T[]);
	int linear_search(int LB,int UB,T[],T key);
	int binary_search(int LB,int UB,T[],T key);
	void selection_sort(int LB,int UB,T[]);
	void bubble_sort(int LB,int UB,T[]);
 	template <class U>
  	friend ostream& operator<<(ostream&, Array<U> );
};