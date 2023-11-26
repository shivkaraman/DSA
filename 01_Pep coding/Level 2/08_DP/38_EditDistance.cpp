// https://leetcode.com/problems/edit-distance/

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
Using recursion ->
level -> c1 and c2
options -> 
    c1 == c2 ans(ros1, ros2, op)
    c1 != c2 -> 3 options 
     1. insert c2 in string1 -> ans(string1, ros2, op+1)
     2. delete c1 in string1 -> ans(ros1, string2, op+1)
     3. replace c1 with c2 in string 1 -> ans(ros1, ros2)
    
Using dp
    strage -> dp[i][j] -> Min op to make string s1 till ith idx equal to s2 till jth idx
    traversal ->
        insert -> dp[i][j-1]
        delete -> dp[i-1][j]
        replace-> dp[i-1][j-1]  
        dp[i][j] = min(insert, delete, replace) + 1 --> if c1 != c2
        dp[i][j] = dp[i-1][j-1] --> if c1 == c2
*/
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 && j == 0)
                dp[i][j] = 0;
            else if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else{
                if(s1[i-1] != s2[j-1])
                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    
    return 0;
}