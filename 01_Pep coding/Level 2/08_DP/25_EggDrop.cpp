// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1


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

int solution (int e, int f){
    vector<vector<int>> dp(e+1, vector<int> (f+1, 0));
    for(int i = 1; i <= e; i++){
        for(int j = 1; j <= f; j++){
            if(i == 1)
                dp[i][j] = j;
            else if(j == 1)
                dp[i][j] = 1;
            else{
                int mn = j;
                for(int mj = j-1, pj = 0; mj >= 0; mj--, pj++){
                    int xb = dp[i-1][pj];
                    int xs = dp[i][mj];
                    int luck = max(xb, xs);
                    mn = min(mn, luck);
                }   
                dp[i][j] = mn + 1;
            }
        }
    }
    return dp[e][f];
}

int main(){
    int e, f;
    cin >> e >> f;

    cout << solution(e, f);
    return 0;
}