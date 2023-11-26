// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

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

//I have used Coin change combination approach to solve this problem
// Storage & meaning -> d[i] = Max price by selling any combination of cut rods summing up to length i
// direction -> 0 > n
// Traverse -> Traverse cut wise (coinwise) for each length (amount)
int solution(vector<int> &prices, int n){
    vector<int> dp (prices.begin(), prices.end());
    for(int cut = 1; cut <= n; cut++){
        for(int len = cut+1; len <= n; len++){
            dp[len] = max(dp[len], dp[len-cut]+dp[cut]);
        }
    }
    return dp[n];
}

//Cut strategy
/*
   1x5 2x4  3x3
    \   |   /
    1\  |2 /3    
      \ | /
       \|/ 
        6
*/
int solution2(vector<int> &prices, int n){
    vector<int> dp (n+1, 0);
    for(int len = 1; len <= n; len++){
        dp[len] = prices[len];
        int l = 1;
        int r = len-1;
        while(l < r){
            dp[len] = max(dp[len], dp[l]+dp[r]);
            l++;
            r--;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;

    vector<int> prices(n+1);
    for(int i = 1; i <= n; i++){
        cin >> prices[i];
    }

    cout << solution(prices, n);
    return 0;
}