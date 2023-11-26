// https://leetcode.com/problems/longest-common-subsequence/description/

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

int lcs(string text1, string text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]) // c1 == c2
                dp[i][j] = 1 + dp[i-1][j-1];
            else                          // c1 != c2
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2);
    return 0;
}