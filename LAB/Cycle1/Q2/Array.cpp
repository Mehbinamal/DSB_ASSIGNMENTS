#include"Array.h"

template<class T>
void Array<T>::setLB(int x){
    LB=x;
}
template <class T> 
void Array<T>::setUB(int x) {
    UB = x;
}
template<class T>
int Array<T>::getLB(){
    return LB;
}
template <class T> 
int Array<T>::getUB() {
    return UB;
}
template <class T>
Array<T>::Array(){
	cout<<"Enter Lover Bound :";
    cin>>LB;
    cout<<"Enter UpperBound: ";
    cin>>UB;
    cout<<"Enter Elements:";
    int i=LB;
    while(i<=UB){
        cin>>A[i];
        i++;
    }
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
int  Array<T>::linear_search(){
    T key;
    cout<<"Enter Value to search:";
    cin>>key;
	int index = -1 ;
	for (int i=LB;i<=UB;i++){
		if  (A[i] == key) {
			index = i;
			break;
		}

	}
	return index;
}

template<class T>
int Array<T>::binary_search(T key){
	if (LB>UB){
		return -1;
	}
	else {
		int mid = (LB + UB)/2;
		if  (key==A[mid]){
			return mid;
		}
		else if (key < A[mid]){
            UB=mid-1;
			return binary_search(key);
		}
		else {
            LB=mid+1;
			return binary_search(key);
		}
	}

}

template <class T>
void Array<T>::selection_sort(){       
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
void Array<T>::bubble_sort()
{       
    for(int i=LB;i<UB-1;i++)
    {
        for(int j=LB;j<=UB+LB-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }
        }
    }
}

template <class T>
void Array<T>::insertion_sort() {
    for (int i = LB + 1; i <= UB; i++) {
        T key = A[i];
        int j = i - 1;
        while (j >= LB && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        if (j != i - 1) {
            A[j + 1] = key;
        }
    }
}
template <class T>
void Array<T>::quick_sort(int LB, int UB) {
    if (LB < UB) {
        int pivot = partition(LB, UB);
        quick_sort(LB, pivot - 1);
        quick_sort(pivot +1, UB);
    }
}

template <class T>
int Array<T>::partition(int LB, int UB) {
    T pivot = A[UB];
    int i = LB - 1;
    for (int j = LB; j < UB ; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[UB]);
    return (i + 1);
}
template <class T>
void Array<T>::swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


template <class T>
void Array<T>::merge( int LB, int mid, int UB) {
    int n1 = mid - LB + 1;
    int n2 = UB - mid;

    T L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[LB + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0;
    int j = 0; 
    int k = LB; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

template <class T>
void Array<T>::merge_sort(int LB, int UB) {
    if (LB < UB) {
        int mid = LB + (UB - LB) / 2;
        merge_sort(LB, mid);
        merge_sort(mid + 1, UB);
        merge(LB, mid, UB);
    }
}

