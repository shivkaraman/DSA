//Given an array of n elements. Output sum of elements of each subarray 
// no of sub arrays = n*(n+1)/2

#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,0,7,2},n=5;

    for(int i=0;i<n;i++){   //O(n^2)
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<" ";
        }
    }
    return 0;
}