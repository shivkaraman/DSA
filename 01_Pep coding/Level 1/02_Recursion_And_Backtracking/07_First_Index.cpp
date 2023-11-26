// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x. 
// 4. You are required to find the first index at which x occurs in array a.
// 5. If x exists in array, print the first index where it is found otherwise print -1.

#include <iostream>
using namespace std;

//Expectation --> The function knows to print the idx at which x is present 
//Faith --> The function knows to print the index at which x is present for arr[1]-arr[n-1]
//F-E --> checkf if arr[0]== count if present return 0 else check if element if present in rest of the array-> ar[1]-arr[n-1]
int firstIndex(int arr[],int idx,int x,int n){
    if(idx==n)
        return -1;
    if(x==arr[idx])
        return idx;
    else
        firstIndex(arr,idx+1,x,n);  //Faith
}
int main(){
    int n;
    cin >> n;

    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> d;

    int p = firstIndex(arr, 0, d, n);
    cout << p << endl;
    return 0;
}
