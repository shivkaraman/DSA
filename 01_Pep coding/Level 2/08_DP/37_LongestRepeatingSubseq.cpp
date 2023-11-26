/*
Given a string, find the length of the longest repeating subsequence, such that the two subsequences don’t have same string character at the same position,
ie for string 
        a b a c b c
        0 1 2 3 4 5

        a b c   a b c  -> Valid
        0 1 3   2 4 5

        a b c   a b c  -> Inalid coz same a(index 0) appeared in both substrings
        0 1 3   0 4 5
*/
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

//SOlution -> Longest commin subsequence with itself but we need to alter c1 == c1 condition. While checking c1==c2, we have to make sure that index[c1] != index[c2] 
int lcs(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1] && i != j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int lrs(string s){
    return lcs(s, s);
}

int main(){
    
    return 0;
}