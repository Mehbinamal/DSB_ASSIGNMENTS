#include <iostream>
using namespace std;

class Matrix {
public:
    int** matrix;
    int row, col;

    friend istream& operator>>(istream& is, Matrix& obj) {
        cout<<"-------------------"<<endl;
        cout<<"Enter number of rows:";
        cin>>obj.row;
        cout<<"Enter the  number of columns:";
        cin>>obj.col;
        cout<<"-------------------"<<endl;
        obj.matrix = new int*[obj.row];
        for (int i = 0; i < obj.row; ++i) {
            obj.matrix[i] = new int[obj.col];
        }
        cout << "Enter the elements of the matrix (no of elements ="<<obj.row*obj.col<<"):" << endl;
        for (int i = 0; i < obj.row; ++i) {
            for (int j = 0; j < obj.col; ++j) {
                is >> obj.matrix[i][j];
            }
        }
        cout<<"-------------------"<<endl;
        return is;
    }
    
    friend ostream& operator<<(ostream& os, const Matrix& obj) {
        cout<<"-------------------"<<endl;
        cout << "The matrix is:" << endl;
        for (int i = 0; i < obj.row; ++i) {
            for (int j = 0; j < obj.col; ++j) {
                os << obj.matrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    friend  Matrix operator+(Matrix a, Matrix b){
        if(a.row != b.row || a.col != b.col){
            cout<<"Matrices are not compatible to add."<<endl;
            exit(-1);
        }
        else{
            Matrix c;
            c.row = a.row;
            c.col = a.col;
            c.matrix = new int*[c.row];
            for (int i=0;i<c.row;++i){
                c.matrix[i] = new int [c.col];
            }
            for (int i=0;i<c.row;++i){
                for (int j=0;j<c.col;j++){
                    c.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
                }
            }
        return c;
        }    
    }

    friend Matrix operator*(Matrix a,Matrix b){
        if(a.col != b.row){
            cout<<"Matrices are not compatible to Multiply."<<endl;
        exit(-1);
        }
        else{
            Matrix c;
            c.row = a.row;
            c.col = b.col;
            c.matrix = new int*[c.row];
            for (int i=0;i<c.row;++i){
                c.matrix[i] = new int [c.col];
            }

            for (int i=0;i<c.row;++i){
                for (int j=0;j<c.col;++j){
                    c.matrix[i][j]=0;
                    for(int k=0;k<a.col;++k){ 
                        c.matrix[i][j] += a.matrix[i][k]*b.matrix[k][j];
                    }
                }
            }
            
            return c;
        }
    }
};
