/*
1. You are given a number n, representing the number of elements.
2. You are given n numbers, representing the contents of array of length n.
3. You are required to print the sum of elements of the increasing subsequence with maximum sum for the array.

Sample Input
10 
10 22 9 33 21 50 41 60 80 1

Sample Output
255
*/
#include<iostream>
#include<vector>
using namespace std;

//Approach is same as Longest increasing subsequence. But here instead of length we calculate the sum
int mis(vector<int> arr, int n){
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    int ans = dp[0];

    for(int i = 1; i < n; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + arr[i];
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

    cout << mis(arr, n);
    return 0;
}
