/*
1. You are given a number N.
2. There are 2*N points on a circle. You have to draw N non-intersecting chords on a circle.
3. You have to find the number of ways in which these chords can be drawn.

Sample Input
3

Sample Output
5
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