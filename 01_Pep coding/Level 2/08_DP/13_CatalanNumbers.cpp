/*
1. You are given a number n.
2. You are required to find the value of nth catalan number.
C0 -> 1
C1 -> 1
C2 -> 2
C3 -> 5
C4 -> 14
..
Cn -> C0.Cn-1 + C1.Cn-2 + .. + Cn-2.C1 + Cn-1.C0

Sample Input
4

Sample Output
14
*/

#include <iostream>
#include <vector>
using namespace std;

/*
//* C2 = C0C1 + C1C0                        = 2C0C1
//* C3 = C0C2 + C1C1 + C2C0                 = 2C0C2 + C1C1
//* C4 = C0C3 + C1C2 + C2C1 + C3C0          = 2C0C3 + 2C1C2
//* C5 = C0C4 + C1C3 + C2C2 + C3C1 + C4C0   = 2C0C4 + 2C1C3 + C2C2
*/
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