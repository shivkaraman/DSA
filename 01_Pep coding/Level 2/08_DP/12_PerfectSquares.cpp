/*
1. You are given a number N.
2. You have to find the minimum number of squares that sum to N.
3. You can always represent a number as a sum of squares of other numbers.
   For eg -> In worst case N can be represented as (1*1) + (1*1) + (1*1)..... N times. 

Sample Input
35

Sample Output
3
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// https://www.youtube.com/watch?v=aZuQXkO0-XA&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=14
int solution(int n){
    vector<int> dp(n+1, 0);
    for(int i = 1; i <= n; i++){
        int mn = n;
        for(int j = 1; (i - j*j) >= 0; j++){
            mn = min(mn, dp[i-j*j]);
        }
        dp[i] = mn+1;
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    cout << solution(n);
    return 0;
}