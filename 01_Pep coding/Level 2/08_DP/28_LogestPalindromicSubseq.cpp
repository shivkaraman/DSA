// https://leetcode.com/problems/longest-palindromic-subsequence/description/

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

int lps(string str){
    int n = str.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = 1;
            else{
                if(str[i] == str[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else    
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }   
    }
    return dp[0][n-1];
}

// Second approach is to use Longest common subsequence solution , passing second stiring as reverse fo the string and finding the longest common subsequence will give longest palindromic subseq
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

int lps2(string s){
    string str = s;
    reverse(s.begin(), s.end());

    return lcs(str, s);
}

int main(){
    string s;
    cin >> s;

    cout << lps(s);
    return 0;
}