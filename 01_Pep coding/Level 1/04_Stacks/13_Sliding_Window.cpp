// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing the elements of array a.
// 3. You are given a number k, representing the size of window.
// 4. You are required to find and print the maximum element in every window of size k.

// e.g.
// for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, 
// the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]
// 1. Find ngetr for all elements 
// 2. Traverse 

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    //Find NGETR of all elements
    int ngetr[n];
    stack<int> s;
    s.push(n-1);  //* In NGETR problem, we used default value as -1, but here we use ARR LENGTH as default value
    ngetr[n-1] = n;
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && arr[s.top()] <= arr[i]){
            s.pop();
        }
        if(s.empty())
            ngetr[i] = n;
        else
            ngetr[i] = s.top();
        s.push(i);
    }
    //*Since we are storing the index of NGETR in ngter[] array, we check if the index of NGETR lies in the window(k) then jump to NGETR and check the same for it, else the current index in the ngetr[] is the max of current window
    for(int i=0; i<=n-k; i++){
        int j = i;
        while(ngetr[j] < i+k){
            j = ngetr[j];
        }
        cout<<arr[j]<<endl;
    }
    return 0; 
} 