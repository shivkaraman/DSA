// Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest amd largest element in 
// the given array. It is given that all array elements are distinct.

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[]={7, 10, 4, 3, 20, 15},n=6;
    int k=3;
    sort(arr,arr+n);
    cout<<"kth max : "<<arr[n-k]<<endl<<"kth min : "<<arr[k-1]<<endl;
    return 0;
}