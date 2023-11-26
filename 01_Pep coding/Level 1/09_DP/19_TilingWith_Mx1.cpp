/*
1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
2. You've an infinite supply of m * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.

Sample Input
39
16

Sample Output
61
*/

#include <iostream>
#include <vector>
using namespace std;

//This is just a variation of prev problem
int countWays(int n, int m){
    vector<int> dp(n+1, 0);
    dp[0] = 1; //*This is just a helper value for horizontal placing , say n = m = 3, dp[i[ = dp[i-1] ie dp[3] = dp[2] for vertical and for horizontal i-m ie 3-3 = 0, so in this case, we can place a horizontal tile, if dp[0]=0 , the horizontal wont be considered
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1]; //Placing vertical
        if(i - m >= 0)   //To place horizontal
            dp[i] += dp[i-m];
    }
    return dp[n];
}

int main() {
    int n ;
    cin >> n;

    int m ;
    cin >> m;

    cout << countWays(n, m);
    return 0;
}