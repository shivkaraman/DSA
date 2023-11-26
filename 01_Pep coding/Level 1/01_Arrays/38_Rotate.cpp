/*
Rotate by 90 degree
1. You are given a number n, representing the number of rows and number of columns.
2. You are given n*n numbers, representing elements of 2d array a.
3. You are required to rotate the matrix by 90 degree clockwise and then display the contents using display function.

4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44

41 31 21 11
42 32 22 12
43 33 23 13
44 34 24 14
*/

#include <iostream>
#include <algorithm>
using namespace std;

void display(int **arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;

    int **arr = new int*[n];
    for(int i=0;i<n;i++)
        arr[i] = new int[n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }

    for(int i=0;i<n;i++){               //Transpose
        for(int j=i+1;j<n;j++){   
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){               //Reverse columns
        for(int j=0;j<n/2;j++)
            swap(arr[i][j],arr[i][n-j-1]);
    }

    display(arr,n);
    return 0;
}