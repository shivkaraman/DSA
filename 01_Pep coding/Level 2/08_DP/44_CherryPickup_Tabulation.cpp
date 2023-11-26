
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
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

        for (int r1 = 0; r1 < n; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = 0; r2 < n; r2++) {
                    int c2 = r1 + c1 - r2;
                    if (dp[r1][c1][r2] != 0 || c2 < 0 || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
                        continue;
                    
                    int cherries = 0;
                    if (r1 == r2 && c1 == c2)
                        cherries += grid[r1][c1];
                    else
                        cherries += grid[r1][c1] + grid[r2][c2];

                    int hh = getDP(dp, r1, c1 - 1, r2);
                    int vv = getDP(dp, r1 - 1, c1, r2 - 1);
                    int vh = getDP(dp, r1 - 1, c1, r2);
                    int hv = getDP(dp, r1, c1 - 1, r2 - 1);

                    cherries += max(max(hh, vv), max(hv, vh));
                    dp[r1][c1][r2] = cherries;
                }
            }
        }

        return max(0, dp[n - 1][n - 1][n - 1]);
    }

private:
    int getDP(const vector<vector<vector<int>>>& dp, int r1, int c1, int r2) {
        if (r1 < 0 || c1 < 0 || r2 < 0)
            return 0;
        return dp[r1][c1][r2];
    }
};

int main(){
    
    return 0;
}
