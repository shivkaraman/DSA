// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int solution (vector<int> coins){
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));

    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = coins[i];
            else if(g == 1)
                dp[i][j] = max(coins[i], coins[j]);
            else{
              
                int val1 = coins[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int val2 = coins[j] + min(dp[i+1][j-1], dp[i][j-2]);

                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin >> n;

    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    cout << solution(coins);
    return 0;
}