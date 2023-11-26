/*
1. You are given a number n, representing the number of days.
2. You are given n numbers, where ith number represents price of stock on ith day.
3. You are given a number k, representing the number of transactions allowed.
3. You are required to print the maximum profit you can make if you are allowed k transactions at-most.
Note - There can be no overlapping transaction. One transaction 

Sample Input
6 
9 6 7 6 3 8 1
Sample Output
5
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
Storage - 2D array
Meaning: dp[i][j] -> Max profit that can be made in first i days in j transactions
Traverse and solve: 
    For example for n = 8 and k = 3, we have 2 options
        1. kth transaction that already occured on n-1 th day ie dp[k][n-1]
        2. We perfomrm the kth transaction on nth day, ie k-1th transaction can be chosen on any day 
           from 1st-n-1th day but we 
           need to max out the profit 
           So we need to choose max between dp[k-1][1]+price[n]-price[1] -> dp[k-1][n-1]+price[n]-price[n-1]
*/
int transactions(vector<int> price,int K){
    int N = price.size();
    vector<vector<int>> dp(K, vector<int>(N+1, 0));
    for(int k = 1; k <= K; k++){
        for(int n = 1; n <= N; n++){
            int kth = INT_MIN; //kth transaction
            for(int x = n-1; x >= 0; x--){
                kth = max(kth, dp[n-1][x] + price[n] - price[x]);
            }
            dp[k][n] = max(dp[k][n-1], kth);
        }
    }
    return dp[K][N];
}

// https://www.youtube.com/watch?v=3YILP-PdEJA&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=35 -> Watch video for optimised
// This is simple, instead of looping to calculate the max of prev row, we are calculating the max as we traverse. Its just like MAX TILL NOW for prev row
int transactionsOptimised(vector<int> price,int K){
    int N = price.size();
    vector<vector<int>> dp(K, vector<int>(N+1, 0));
    for(int k = 1; k <= K; k++){
        int mx = INT_MIN;
        for(int n = 1; n <= N; n++){
            mx = max(mx, dp[k-1][n-1]-price[n-1]);
            dp[k][n] = max(dp[k][n-1], mx+price[n]);
        }
    }
    return dp[K][N];
}

int main(){
    int n;
    cin>>n;

    vector<int> price(n,0);
    for (int i = 0; i < n; i++){
        cin>>price[i];
    }
    int k ;
    cin>>k;

    transactions(price,k);
    return 0;
}