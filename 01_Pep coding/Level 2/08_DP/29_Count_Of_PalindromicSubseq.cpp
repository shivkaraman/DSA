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

int count_of_ps(string str){
    int n = str.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = 1;
            else{
                if(str[i] == str[j])
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                else    
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        }   
    }
    return dp[0][n-1];
}

int main(){
    string s;
    cin >> s;

    cout << count_of_ps(s);
    return 0;
}