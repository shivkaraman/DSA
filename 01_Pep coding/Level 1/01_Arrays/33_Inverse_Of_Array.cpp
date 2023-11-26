/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to calculate the inverse of array a.

Inverse --> if a[x]=y
            then a[y]=x
*/

#include <iostream>
using namespace std;

int* inverse(int arr[],int n){
    int * inverse = new int[n];
    for(int i=0;i<n;i++)
        inverse[arr[i]]=i;
    return inverse;
}

int main(){
    int n;
    cin>>n;
    
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++)
        cin>>arr[i];    

    arr = inverse(arr,n);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        
    return 0;
}