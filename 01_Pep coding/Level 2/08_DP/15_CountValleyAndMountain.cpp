/*
1. You are given a number n, representing the number of upstrokes / and number of downstrokes .
2. You are required to find the number of valleys and mountains you can create using strokes.

1 -> /\

      /\ 
2 -> /  \ or /\/\

                /\
     /\/\      /  \      /\          /\
3-> /    \ or /    \ or /  \/\ or /\/  \ or /\/\/\

Sample Input
4

Sample Output
14

*/

#include <iostream>
#include <vector>
using namespace std;

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

    cout << catalan(n);
    return 0;
}