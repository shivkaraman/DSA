/*
Write a program to peint all subsequence of an array
This can be done using bit masking method

for n=3, no of subsets = 2^3 = 8
arr[3]={1,2,3}
0 0 0   ->  _ _ _
0 0 1   ->  _ _ 3
0 1 0   ->  _ 2 _
0 1 1   ->  _ 2 3
1 0 0   ->  1 _ _
1 0 1   ->  1 _ 3
1 1 0   ->  1 2 _
1 1 1   ->  1 2 3 
*/

#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int limit=pow(2,n); //No of subsequence of an array of n elements : 2^n
    for(int i=0;i<limit;i++){
        int idx=0;
        for(int j=n-1;j>=0;j--){
            if((i & (1<<j)) != 0)
                cout<<arr[idx]<<" ";
            else    
                cout<<"_ ";
            idx++;
        }
        cout<<endl;
    }
    return 0;
}