
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

//Storage -> dp[i][j] lcs of two stings including ith  and jth character
int lcs(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    int longest = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = 0;
            longest = max(longest, dp[i][j]);
        }
    }
    return longest;
}

int main(){
    cout << lcs("xyzabcp", "pqabcxy");
    return 0;
}