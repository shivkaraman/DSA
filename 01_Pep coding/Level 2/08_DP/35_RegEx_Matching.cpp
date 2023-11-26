// https://leetcode.com/problems/regular-expression-matching/

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
    //This is similar to previous onw. Here when we get *, we process the prev character of pattern along with *
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[n][m] = true;

        for(int i = n-1; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(p[i+1] == '*'){
                    dp[i][j] = dp[i+1][j];
                }
                else if(j == m){
                    if(p[i] == '*')
                        dp[i][j] = dp[i+1][j];
                }
                else{
                    if(p[i] == '.')
                        dp[i][j] = dp[i+1][j+1];
                    else if(p[i] == '*'){
                        bool zeroApp = dp[i+1][j];                                             //zero appearance
                        bool oneApp = dp[i+1][j+1] && (p[i-1] == '.' ? true : p[i-1] == s[j]); //one appearance
                        bool twoOrMore = dp[i][j+1]&& (p[i-1] == '.' ? true : p[i-1] == s[j]); //two or more appearance
                        dp[i][j] = zeroApp || oneApp || twoOrMore;
                    }
                    else
                        dp[i][j] = dp[i+1][j+1] && p[i] == s[j];
                }
            }   
        }
        return dp[0][0];
    }
};

int main(){
    string p, s;
    cin >> s >> p;

    Solution S;
    cout << S.isMatch(s, p);
    return 0;
}