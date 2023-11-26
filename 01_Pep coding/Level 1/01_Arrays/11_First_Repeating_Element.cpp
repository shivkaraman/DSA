//Amazon, Oracle
/*
Given an array of n elements. The task is to find the  first repeating element in an array of integers ie the element that 
occues more than once and whose index of first occurance is smallest
*/
#include <iostream>
#include <climits>
using namespace std;

int main(){
    int arr[]={1,5,3,4,3,5,6}, n=7;
    const int N=1e3;
    int idx[N];
    int min_idx = INT_MAX;

    for(int i=0;i<N;i++)
        idx[i] = -1;

    for(int i=0;i<n;i++){
        if(idx[arr[i]] != -1)
            min_idx = min(min_idx, idx[arr[i]]);
        else
            idx[arr[i]] = i;
    }
    if(min_idx == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<"First repeating element is : "<<arr[min_idx]<<endl<<" Present at index "<<min_idx<<endl;
    return 0;
}