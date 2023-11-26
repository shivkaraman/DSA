
#include <iostream>
using namespace std;

void print(int arr[][5],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int matrix[5][5]={1, 5, 7, 9,10,
                      6, 10,12,13,20,
                      9, 25,29,30,32,
                      15,55,59,63,68,
                      40,70,79,81,95};
    int n=5, m=5;
    print(matrix,n,m);

    for(int i=0;i<n-1;i++){   
        for(int j=i+1;j<m;j++){   //j=i+1 coz we cinsider only upper triangular matrix
      //for(int j=0;j<i;j++){    // To consider lower triangular matrix
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    cout<<"Transpose : "<<endl;
    print(matrix,n,m);
    return 0; 
}