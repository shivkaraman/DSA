/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the prices of a share on n days.
3. You are required to find the stock span for n days.
4. Stock span is defined as the number of days passed between the current day and the first day before today when price was higher than today.

e.g.
for the array [2 5 9 3 1 12 6 8 7]
span for 2 is 1
span for 5 is 2
span for 9 is 3
span for 3 is 1
span for 1 is 1
span for 12 is 6
span for 6 is 1
span for 8 is 2
span for 7 is 1

This is like NEXT GREATEST ELEMENT TO LEFT
 
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void StockSpan(int arr[], int n){
    stack<int> s;
    for(int i=0; i<n; i++){
        int idx = i ;
        while(!s.empty() && arr[s.top()] <= arr[i]){ //Popping all smallerr elements to left
            s.pop();
        }
        if(s.empty())                               //If no element is greater then the current element, print current index + 1
            cout<<i+1<<endl;
        else                                        //If its not empty, it means we have the NGETL
            cout<<i-s.top()<<endl;
        s.push(i);                                  //Push current index
    }   
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    StockSpan(arr, n);
    return 0;
}