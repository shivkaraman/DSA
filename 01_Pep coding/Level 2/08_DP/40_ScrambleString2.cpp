// https://www.youtube.com/watch?v=x4BzQu6u9X0&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=42

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

class Solution {
public:
    //dp[len][i][j] -> s1.substr(i, i+len) is samble of s2.substr(j, j+len)
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n, vector<int>(n)));        
        for (int i = 0; i < n; i++) { // len 1
            for (int j = 0; j < n; j++) {
                
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n-len; i++) {
                for (int j = 0; j <= n-len; j++) {
                    if(len == 1){
                        dp[len][i][j] = s1[i] == s2[j];
                        continue;
                    }
                    for(int k = 1; k < len && !dp[len][i][j]; k++){
                        //Indexing is same as in recursion  i->si1  j->si2  k->len  
                        dp[len][i][j] = (dp[k][i][j] && dp[len-k][i+k][j+k]) || (dp[k][i][j+len-k] && dp[len-k][i+k][j]);
                    }
                    
                }
            }
        }
        return dp[n][0][0];
    }
};

int main(){
    
    return 0;
}