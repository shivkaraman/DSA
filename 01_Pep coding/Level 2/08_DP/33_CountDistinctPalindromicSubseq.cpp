
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

int count_distinct_palindroimc_subseq(string str){
    int n = str.size();
    vector<int> next(n, -1);
    vector<int> prev(n, -1);
    unordered_map<char, int> mp;

    // Filling the previous array
    for(int i = 0; i < n; i++){
        char ch = str[i];
        if(mp.find(ch) == mp.end())
            prev[i] = -1;
        else    
            prev[i] = mp[ch];
        mp[ch] = i;
    }

    // Filling the next array
    mp.clear();
    for(int i = n; i >= 0; i--){
        char ch = str[i];
        if(mp.find(ch) == mp.end())
            next[i] = -1;
        else    
            next[i] = mp[ch];
        mp[ch] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = 1;
            else if(g == 1)
                dp[i][j] = 2;
            else{
                char c1 = str[i];
                char c2 = str[j];
                if(c1 != c2){ // dp[str] = dp[c1m] + dp[mc2] - dp[m]
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
                }
                else{
                    int n = next[i];
                    int p = prev[j];
                    int mid = dp[i+1][j-1];
                    if(n > p)       
                        // a <-----> a   -> dp[str] = 2*dp[mid]+2
                        dp[i][j] = 2*mid + 2;
                    else if(n == p) 
                        // a <-- a ---> a -> dp[str] = 2*dp[mid]+1
                        dp[i][j] = 2*mid + 1;
                    else
                        //           m'            
                        // a <----a ---- a ---> a -> dp[str] = 2*dp[mid] - dp[m']
                        dp[i][j] = 2*mid - dp[n+1][p-1];
                }
            }
        }
    }
    return dp[0][n-1];
} 

int main(){
    string str;
    cin >> str;

    cout << count_distinct_palindroimc_subseq(str);
    return 0;
}