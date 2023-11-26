// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number x. 
// 4. You are required to find the all indices at which x occurs in array a.
// 5. Return an array of appropriate size which contains all indices at which x occurs in array a.

#include <iostream>
using namespace std;

//Expectation --> The function knows to print the last idx of x 
//Faith --> The function knows to print the last index of is present for arr[1]-arr[n-1]
//F-E --> Find the last idx of occurance of x and return idx, if not found in arr[1]-arr[n-1] check if arr[0]=x if yes return 0
int lastIndex(int arr[], int idx, int x, int n){
    if(idx==n)
        return -1;
        
    int li=lastIndex(arr,idx+1,x,n);
    if(li == -1 && arr[idx]==x)
        return idx;
    else
        return li;
} 

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}