/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the height of bars in a bar chart.
3. You are required to find and print the area of largest rectangle in the histogram.

e.g.
for the array [6 2 5 4 5 1 6] -> 12
1. Find right bnoundary of the current bar{ie nothing but next smaller elemment to right}
2. Find left bnoundary of the current bar{ie nothing but next smaller elemment to left}
3. find max area 
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    //Next smaller element to right(index)
    //Rigth boundary
    int rb[n];  
    stack<int> s1;
    rb[n-1] = n;
    s1.push(n-1 );
    for(int i=n-2; i>=0; i--){
        while(!s1.empty() && arr[s1.top()] >= arr[i]){
            s1.pop();
        }
        if(s1.empty())
            rb[i] = n;
        else
            rb[i] = s1.top();
        s1.push(i);
    }
    //Left boundary
    int lb[n];
    stack<int> s2;
    s2.push(0);
    lb[0] = -1;
    for(int i=1; i<n; i++){
        while(!s2.empty() && arr[s2.top()] >= arr[i]){
            s2.pop();
        }
        if(s2.empty())
            lb[i] = -1;
        else
            lb[i] = s2.top();
        s2.push(i);
    }

    //Maximum area
    int maxArea = 0;
    for(int i=0; i<n; i++){
        int width = rb[i] - lb[i]-1;
        int current = width * arr[i];
        maxArea = max(maxArea,current);
    }
    cout<<maxArea;
    return 0;
}