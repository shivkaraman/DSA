// 1. You are given a number n, representing the number of rows and columns of a square matrix.
// 2. You are given n * n numbers, representing elements of 2d array a.
// 3. You are required to diagonally traverse the upper half of the matrix and print the contents.

// 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44

// 11 22 33 44 12 23 34 13 24 14

#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    //Array declaration and input
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
        arr[i] = new int[n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }    

    //Diagonal Traversal
    for(int g = 0; g < n ;g++){
        for(int i = 0, j = i + g; j < n; i++, j++)
            cout<<arr[i][j]<<" ";
    }
    return 0;
}