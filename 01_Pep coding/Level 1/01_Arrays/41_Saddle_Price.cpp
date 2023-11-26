// 1. You are given a square matrix of size 'n'. You are given n*n elements of the square matrix. 
// 2. You are required to find the saddle price of the given matrix and print the saddle price. 
// 3. The saddle price is defined as the least price in the row but the maximum price in the column of the matrix.

#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> max_col(int **a,int n,int idx){
    int Max=INT_MIN;
    pair<int,int>index;
    for(int i=0;i<n;i++){
        if(a[i][idx]>Max){
            Max=a[i][idx];
            index={i,idx};
        }
    }
    return index;
}
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

    int i,j;
    pair<int,int>idx;
    for(int i=0;i<n;i++){
        int Min=INT_MAX;
        for(j=0;j<n;j++){
            if(arr[i][j] < Min){
                Min=arr[i][j];
                idx={i,j};
            }
        }
        pair<int,int> x= max_col(arr,n,idx.second);
        if(idx == x){
            cout<<arr[idx.first][idx.second];
            exit(0);
        }
        j++;
    }
    cout<<"Invalid input";
    return 0;
}