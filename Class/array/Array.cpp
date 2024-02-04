#include"Array.h"


template <class T>
Array<T>::Array(){
	LB=1;
	UB=0;
}
template <class T>
Array<T>::Array(int LBound,int UBound,T x[]){
	LB = LBound;
	UB = UBound;
	int i =LB;
	int index = 0;
	while (i<=UB){
		A[i] = x[index++];
		++i;
	}
}
template <class T>
void Array<T>::insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template <class U>
ostream& operator << (ostream& os,Array<U> M){
	int i;
	os<<endl;
	for (i=M.LB;i<=M.UB;i++){
		os<<M.A[i]<<" ";
	}
	os<<endl;
	return os;
}

template <class T>
void Array<T>::insert_at_beginning(int LB,int UB,T[],T key){
	UB = UB +1;
	int k = UB - 1;
	while (k>=LB) {
		A[k+1] = A[k];
		k = k-1;
	}
	A[LB] = key;
}

template <class T>
void Array<T>::insert_at_position(int LB,int UB,T[],T key,int pos){
	UB = UB +1;
	int k = UB - 1;
	while (k>=pos) {
		A[k+1] = A[k];
		k = k-1;
	}
	A[pos] = key;
}

template <class T>
void Array<T>::delete_at_end(){
	UB = UB - 1;
}
template <class T>
void Array<T>::delete_at_beginning(int LB,int UB,T[]){
    if (LB<=UB)
    {
        int k=LB+1;
        while (k<=UB)
        {
            A[k-1]=A[k];
            k=k+1;
        }
        UB=UB-1;
    }
    else
    {
        cout<<"\nIndex out of bound\n";
    }
}

template <class T>
int  Array<T>::linear_search(int LB,int UB,T[],T key){
	int index = -1 ;
	int n = UB - LB  + 1;
	for (int i=0;i<n;i++){
		if  (A[i] == key) {
			index = i;
			break;
		}
		index = index + LB;
	}
	return index;
}

template<class T>
int Array<T>::binary_search(int LB,int UB,T[],T key){
	if (LB>UB){
		cout << "\nElement not found" << endl;
		exit(-1);
	}
	else {
		int mid = (LB + UB)/2;
		if  (key==A[mid]){
			return mid;
		}
		else if (key < A[mid]){
			return binary_search(LB,mid-1,A,key);
		}
		else {
			return binary_search(mid+1,UB,A,key);
		}
	}

}

template <class T>
void Array<T>::selection_sort(int LB,int UB,T[]){       
    for(int i=LB;i<UB;i++)
    {
        int min=i;
        for(int j=i+1;j<=UB;j++)
        {
            if(A[j]<A[min])
            {
                 min=j;
            }
        }    
        if (min!=i)
        {
            int temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }
        
    }
}

template <class T>
void Array<T>::bubble_sort(int LB,int UB,T[])
{       
    for(int i=LB;i<UB;i++)
    {
        for(int j=LB;j<=UB+LB-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j+1];
                A[j+1]=A[j];
                A[j]=temp;
            }
        }
    }
}


