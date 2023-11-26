/*
1. You are given an array of numbers.
2. You have to find 2 non-repeating numbers in an array.
3. All repeating numbers are repeating even number of times.

Sample Input
    6
    23 27 23 17 17 37

Sample Output
    27
    37

*/

#include<iostream>
#include<vector>
using namespace std;

void solution(vector<int>&arr){
    int n1XORn2 = 0;
    for(int i : arr)
        n1XORn2 ^= i;

    int rsbm = n1XORn2 & -n1XORn2;
    int n1 = 0, n2 = 0;
    for(int i : arr){
        if((i & rsbm)== 0)
            n1 ^= i;
        else
            n2 ^= i;
    } 
    if(n1<n2) 
        cout << n1 <<endl << n2 << endl; 
    else
        cout << n2 <<endl<< n1 << endl;
}
int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    solution(arr);
}   