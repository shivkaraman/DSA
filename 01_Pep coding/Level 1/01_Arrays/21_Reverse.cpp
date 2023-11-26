
#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void Reverse(int arr[], int n){
    for(int i=0;i<n/2;i++)
        swap(arr[i],arr[n-i-1]);

    // int i=0,j=n-1;
    // while(i<j){
    //     swap(arr[i],arr[j]);
    //     i++;
    //     j--;
    // }
}

int main(){
    int arr[]={1,2,3,4,5},n=5;
    cout<<"Array : "; print(arr,n);

    reverse(arr, arr+n);    //Using STL
    cout<<"Reversed Array : "; print(arr,n);

    Reverse(arr,n);
    cout<<"Reversed Array : "; print(arr,n);
    return 0;
}  