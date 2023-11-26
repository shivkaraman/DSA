/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to "next greater element on the right" for all elements of array
4. Input and output is handled for you.

"Next greater element on the right" of an element x is defined as the first element to right of x having value greater than x.
Note -> If an element does not have any element on it's right side greater than it, consider -1 as it's "next greater element on right"
e.g.
for the array [2 5 9 3 1 12 6 8 7]
Next greater for 2 is 5
Next greater for 5 is 9
Next greater for 9 is 12
Next greater for 3 is 12
Next greater for 1 is 12
Next greater for 12 is -1
Next greater for 6 is 8
Next greater for 8 is -1
Next greater for 7 is -1

https://www.youtube.com/watch?v=rSf9vPtKcmI
Step 1: Declare a stack and push the last element into the stack.
Step 2: Traverse the array from R-> L and pick the array element one by one.
Step 3: If the incoming array element is greater than the top element of the stack, then pop elements the stacks until the top of 
        stack is greater than the array element ,then top is the next greater element(if stack is empty, print -1). If not, then 
        print the stack top and push the incoming array element into the Stack.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int* NGETR(int *arr, int n){
    stack<int> s;
    int *ans = new int[n];
    ans[n-1] = -1;
    s.push(arr[n-1]);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && arr[i] >= s.top()){   //* Pop all smaller elements to right(which is stored in stack)
            s.pop();
        }
        if(s.empty())                             //* IF stack is empty, it means there is no element greater than current element
            ans[i] = -1;
        else                                      //* If not empty, it means there is an element greater than current element
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int* ans = NGETR(arr, n);
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";
    return 0;
}