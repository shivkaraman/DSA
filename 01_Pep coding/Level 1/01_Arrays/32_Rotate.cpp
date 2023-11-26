// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are given a number k.
// 4. Rotate the array a, k times to the right (for positive values of k), and to
// the left for negative values of k.

#include <iostream>
using namespace std;

void reverse(int arr[],int s, int e){
     while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i]; 
    
    int k;
    cin>>k;

    k=k%n;
    if(k<0)
        k+=n;
    
    int s=n-k;
    int e=n-1;
    reverse(arr,s,e);   //Reverse the last k elements

    s=0;
    e=n-k-1;
    reverse(arr,s,e);   //Reverse the elements till n-k th index

    s=0,e=n-1;
    reverse(arr,s,e);   //Reverse the array

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}