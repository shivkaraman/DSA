// https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1
// https://www.youtube.com/watch?v=9UEHPiK53BA&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=34

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

int sol(string s){
    int n = s.size();
    unordered_map<char, int> mp;
    vector<int> dp(n+1);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] * 2;

        char ch = s[i-1];
        if(mp.find(ch) != mp.end())
            dp[i] -= dp[mp[ch]-1];
        
        mp[ch] = i;
    } 
    return dp[n];
}
int main(){
    string s;
    cin >> s;

    cout << sol(s);
    return 0;
}