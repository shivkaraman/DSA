/*
Given an array, find the subarray (containing at least k numbers) which has the largest sum. 
Input : arr[] = {-4, -2, 1, -3} 
            k = 2
Output : -1
The sub array is {-2, 1}

Input : arr[] = {1, 1, 1, 1, 1, 1} 
            k = 2
Output : 6 
The sub array is {1, 1, 1, 1, 1, 1}
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int kadanes(vector<int> &arr, vector<int> &dp){
    int currSum = 0;
    int mxSum = 0;
    dp[0] = 0;
    for(int i = 0; i < arr.size(); i++){
        if(currSum >= 0)
            currSum += arr[i];
        else    
            currSum = arr[i];
        mxSum = max(mxSum, currSum);
        dp[i] = mxSum;
    }
    return mxSum;   
}

vector<int> Ksum(vector<int> &arr, int k){
    vector<int> sum(arr.size());
    int s = 0;
    for(int i = 0; i < k-1; i++){
        s += arr[i];
    }

    int si = 0;
    for(int i = k-1; i < arr.size(); i++, si++){
        s += arr[i];
        sum[i] = s;
        s -= arr[si];
    }
    return sum;
}

int ans(vector<int> &arr, int k){
    vector<int> dp(arr.size());
    kadanes(arr, dp);

    vector<int> ksum = Ksum(arr, k); //Sum of arr[i-k] -> arr[i]
    int maxKsum = ksum[k-1];
    for(int i = k; i < arr.size(); i++){
        int currSum = dp[i-k] + ksum[i];
        maxKsum = max(maxKsum, currSum);
    }
    return maxKsum;
}   

int main(){
    // vector<int>arr = {-4, -2, 1, -3};
    vector<int>arr =  {1, 1, 1, 1, 1, 1};
    int k = 2;
    cout << ans(arr, k);
    return 0;
}