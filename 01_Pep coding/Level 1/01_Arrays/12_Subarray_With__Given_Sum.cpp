// Google, Facebook, Amazon

// Given an  array or n elements, find the subarray with given sum
/*
Bruteforce--> Find sum of all possible subarrays. If any of the sum equatd to Sum, output the starting and ending indez of 
the subarray->O(n^2)

Optimised approach --> O(n) --> 2- Pointer method
1. Keep two pointers s and e and a variable currSum having the value of sum of elements from s to e
2. Increment e till currSum + arr[e]> Sum(given)
3. Start incrementing s until currSum = sum and note the indices of the sub array
*/


#include <iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,7,5}, n=5, sum=18;
    int s=0, e=0, currSum=0;

    while(e<n && (currSum + arr[e] <= sum)){
        currSum+=arr[e];
        e++;
    }
    
    if(currSum == sum){
        cout<<"Range (indices) : ["<<s<<" , "<<e-1<<"]"<<endl;
        exit(0);
    }

    while(e<n){ 
        currSum+=arr[e];
        while(currSum>sum){
            currSum -= arr[s];
            s++;
        }

        if(currSum==sum){
            cout<<"Range (indices) : ["<<s<<" , "<<e<<"]"<<endl;
            exit(0);
        }
        e++;
    }
    cout<<"Subarray with given sum NOT FOUND"<<endl;
    return 0;
}