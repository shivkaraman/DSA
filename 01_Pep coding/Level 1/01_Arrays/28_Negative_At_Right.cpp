//Given an array of n elements, put all negative elements to one side

#include <iostream>
#include <algorithm>
using namespace std;
bool IsNegative(int i){
    return (i<0);
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //All use O(n)
    
    // partition(arr,arr+n,IsNegative);

    // int j=0;                //Keeping negative elements to left
    // for(int i=0;i<n;i++){
    //     if(arr[i]<0){
    //         swap(arr[i],arr[j]);
    //         j++;
    //     }
    // }
    
    int j=0;                //Keeping negative elements to right
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

