
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

int count_of_PS(string str){
    int n = str.size();
    vector<vector<bool>> dp(n, vector<bool> (n, 0));
    
    int count = 0;
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = true;
            else if (g == 1)
                dp[i][j] = (str[i] == str[j]);
            else
                dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]);
            
            if(dp[i][j] == true)
                count++;
        }
    }
    return count;   
}

int main(){
    string s;
    cin >> s;

    cout << count_of_PS
(s);
    return 0;
}