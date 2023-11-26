/*
1. You are given a number n, representing the number of opening brackets ( and closing brackets )
2. You are required to find the number of ways in which you can arrange the brackets if the closing brackets should never exceed opening brackets
e.g.
for 1, answer is 1 -> ()
for 2, answer is 2 -> ()(), (())
for 3, asnwer is 5 -> ()()(), () (()), (())(), (()()), ((()))
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