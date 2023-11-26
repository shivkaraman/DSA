// https://www.youtube.com/watch?v=NbgUZAoIz3g&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=36
// https://leetcode.com/problems/wildcard-matching/

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
    /*
        Recursive solution
        Level character of the pattern
        Option -> * or ? or 'ch'
            ? -> just go to the next character -> p[i+1] s[j+1]
            ch -> jump to next character if p[i] matches s[j]
            * -> we have options to consider 0 -> n characters 
     */
    bool helper(string s, int si, string p, int pi){
        // Base cases
        if(pi == p.size() && si < s.size())
            return false;
        if(pi < p.size() && si == s.size()){
            for(int i = pi; i < p.size(); i++){
                if(p[i] != '*')
                    return false;
            }
            return true;
        }
        if(pi == p.size() && si == s.size())
            return true;

        //Test cases
        if(p[pi] == '?'){
            return helper(s, si+1, p, pi+1);
        }
        else if(p[pi] == '*'){
            if(pi == p.size()-1)
                return true;
            for(int i = si; i < s.size(); i++){
                bool check = helper(s, i, p, pi+1);
                if(check)
                    return true;
            }
            return false;
        }
        else{
            if(s[si] == p[pi])
                return helper(s, si+1, p, pi+1);
            else
                return false;
        }
    }
    bool isMatch(string s, string p) {
        return helper(s, 0, p, 0);
    }
    /*
    
        In recursive approach we followed a bottom up approah => in dp we ahve to traverse from right -> left
        Storage -> dp[i][j]  if pattern[i -> size-1] matches with string[i-> size-1]

        dp[i][j]->
            ? -> current string matches if dp[i+1][j+1] matchesie pattern[i+1->size-1] matches string[j+1->size-1]
            ch -> current string matches if p[i] = s[i] && dp[i+1][j+1] matchesie pattern[i+1->size-1] matches string[j+1->size-1]
            * -> it can be either 0, 1, 2 ... n character long
                 Eg -> 
                      c   b   j   s   d  f   -
                    ?   |   |   |   |   |   |
                    * t | t | t |   |   |   | 
                    j   |   | t |   |   |   | 
                    * t | t | t | t | t | t |   
                    -                         t
                row * is true for all the cols on and before col j coz 
                    if jsdf is true then * can be cbj as sdf is true
                                                  cb  asjsdf is true   
    */
    bool isMatch2(string s, string p){
        int n = p.size();
        int m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[n][m] = true; //empty pattern matches empty string

        for(int i = n-1; i >= 0; i--){
            for(int j = m; j >= 0; j--){
                if(j == m){
                    if(p[i] == '*')
                        dp[i][j] = dp[i+1][j];
                }
                else{
                    if(p[i] == '?')
                        dp[i][j] = dp[i+1][j+1];
                    else if(p[i] == '*')
                        dp[i][j] = dp[i+1][j] || dp[i][j+1];
                    else
                        dp[i][j] = dp[i+1][j+1] && p[i] == s[j];
                }

            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution s;
    cout << s.isMatch2("", "***?");
    return 0;
}