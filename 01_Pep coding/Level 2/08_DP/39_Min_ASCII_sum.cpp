// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

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

/*
Recursive approach
Level -> si1 of s1 and si2 of s2
Options -> if s1[si1] == s2[si2] then do nothing
           else we can delete s1[si1] OR s2[si2]
*/
int ans = INT_MAX;
unordered_set<string> s;
void helper(string &s1, string &s2, int si1, int si2, int sum){
    if(si1 == s1.size() && si2 == s2.size()){
        ans = min(ans, sum);
        return;
    }
    string sub1 = s1.substr(si1);
    string sub2 = s2.substr(si2);

    if(s.find(sub1+sub2) != s.end()){
        return;
    }
    if(si1 != s1.size() && si2 != s2.size() && s1[si1] == s2[si2])
        helper(s1, s2, si1+1, si2+1, sum);
    else{
        if(si1 != s1.size())
            helper(s1, s2, si1+1, si2, sum+s1[si1]);
        if(si2 != s2.size())
            helper(s1, s2, si1, si2+1, sum+s2[si2]);
    }
    s.insert(sub1+sub2);
}

int minimumDeleteSum(string s1, string s2) {
    helper(s1, s2, 0, 0, 0);
    return ans;
}

//DP approach
int minimumDeleteSum2(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = dp[i][j-1] + s2[j-1];
            else if(j == 0)
                dp[i][j] = dp[i-1][j] + s1[i-1];
            else{
                if(s1[i-1] != s2[j-1])
                    dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    cout << minimumDeleteSum2("sea", "eat");
    return 0;
}