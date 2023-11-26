/*
1. You are given a number n, representing the number of elements.
2. You are required to find the number of Binary Search Trees you can create using the elements.

Sample Input
4

Sample Output
14
*/

#include <iostream>
#include <vector>
using namespace std;

// https://www.youtube.com/watch?v=H1qjjkm3P3c&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=16
int countbst(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){ //If jth element is the root
            int left = dp[j-1];
            int right = dp[i-j];

            dp[i] += left * right;
        }
    }
    return dp[n];
}

// if we observe the problem it is just catalan numbers
int catalan(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i= 2; i <= n; i++){
        int ith = 0;
        for(int j = 0; j < i/2; j++){   
            ith += dp[j] * dp[i-j-1];
        }
        dp[i] = 2 * ith + (i%2 != 0 ? dp[i/2]*dp[i/2] : 0);
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    // cout << countbst(n);
    cout << catalan(n);
    return 0;
}