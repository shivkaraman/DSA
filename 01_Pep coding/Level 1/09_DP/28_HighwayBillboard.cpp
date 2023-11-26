/*
You are given a number n representing the length of highway
You are given m billboards and an 2 arrays 
1. m indices where the billboards can be planted
2. m numbers representing the value gained by the billboards
You are given an another integer which represents minimum distance between two billboards 

You have to plant 2 billboards to obtain max value
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Both solutions are optimal. We choose whichever is lower n or m^2 depending on the constraints
int solution1(int n, int m, vector<int> &idx, vector<int> &value, int dist){ //O(m^2) solution
    vector<int> dp(m, 0); //Max value gained given tht the current billboard is manditory
    dp[0] = value[0];
    for(int i = 1; i < m; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(idx[i] - idx[j] > dist){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + value[i];
    }
    return dp[m-1];
}

int solution2(int n, int m, vector<int> &idx, vector<int> &value, int dist){ //O(n) solution
    unordered_map<int, int> mp;
    for(int i = 0; i < m; i++){
        mp[idx[i]] = value[i];
    }

    vector<int> dp(m+1, 0); 
    for(int i = 1; i <= n; i++){
        if(mp.find(i) == mp.end())  
            dp[i] = dp[i-1];
        else{   
            int billBoardInstalled = mp[i] + dp[i-dist-1];
            int billBoardNotInstalled = dp[i-1];
            dp[i] = max(billBoardInstalled, billBoardNotInstalled);
        }
    }
    return dp[m];
}

int main(){
    int n;
    cin >> n;

    int m;
    cin >> m;
    vector<int> indices(m);
    for(int i = 0; i < m; i++) cin >> indices[i];

    vector<int> value(m);
    for(int i = 0; i < m; i++) cin >> value[i];
    
    int dist;
    cin >> dist;

    cout << solution1(n, m, indices, value, dist);
    return 0;
}