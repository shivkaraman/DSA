/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
     overflowing it's capacity.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item 
               again and again.
https://www.youtube.com/watch?v=bUSaenttI24&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=17
*/

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

// This is same as Target sum subset
// No duplicacy => 2D array
// Meaning : dp[i][j]-> Max value that can be created from first i items with max capacity of bag=j
// Direction : [0][0]->[n][tar]
void zeroOneKnapsack(int n,vector<int> val, vector<int> weight,int cap){
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i = 1; i <= n; i++){
        for(int currCap = 1; currCap <= cap; currCap++){
            if(currCap < weight[i-1]) //Current item doenst contribute
                dp[i][currCap] = dp[i-1][currCap];
            else{
                int prevCap = dp[i-1][currCap]; //If curr item doesnot contribute
                int currPlusPrev = val[i-1] + dp[i-1][currCap-weight[i-1]];//If current item contributes
                dp[i][currCap] = max(currPlusPrev, prevCap);
            }
        }
    }
    cout << dp[n][cap];
}    

int main(){
    int n;
    cin >> n;
  
    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    
    int cap;
    cin >> cap;
    
    zeroOneKnapsack(n,val,weight,cap);
    return 0;
}