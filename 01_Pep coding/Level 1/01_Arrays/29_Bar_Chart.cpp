/*
1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print a bar chart representing value of arr a.

Sample Input
    5
    3 1 0 7 5
Sample Output
    			*		
    			*		
    			*	*	
    			*	*	
    *			*	*	
    *			*	*	
    *	*		*	*	
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n],mx=INT_MIN;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    
    int h=mx;
    for(int i=0;i<mx;i++){
        for(int j=0;j<n;j++){
            if(arr[j]==h){
                cout<<"*  ";
                arr[j]--;
            }
            else    
                cout<<"   ";
        }
        h--;
        cout<<endl;
    }
    return 0;
}