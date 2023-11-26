// https://leetcode.com/problems/longest-increasing-subsequence/
// 

#include <iostream>
#include <vector>
using namespace std;
/*
//* Meaning-> dp[i] -> Longest increasing subsequence till ith number that ends with arr[i]
//* direction-> 0->n
//* 
//* Why did we choose ending with arr[i] -> https://youtu.be/odrfUCS9sQk?t=704
*/
int lis(vector<int> arr, int n){
    vector<int> dp(n, 0);
    dp[0] = 1;
    int ans = 1;

    for(int i = 1; i < n; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << lis(arr, n);
    return 0;
}