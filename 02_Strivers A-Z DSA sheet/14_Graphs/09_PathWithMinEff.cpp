
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        while(!pq.empty()){
            int effort = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == m-1) return effort;

            for(auto &p : dir){
                int nr = row + p.first;
                int nc = col + p.second;

                if(nr >= n || nc >= m || nr < 0 || nc < 0) continue;

                int effTillNow = max(effort, abs(grid[nr][nc] - grid[row][col]));

                if(effTillNow < dist[nr][nc]){
                    dist[nr][nc] = effTillNow;
                    pq.push({effTillNow, {nr, nc}});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{1,2,2},{3,8,2},{5,3,5}};
    Solution s;
    s.minimumEffortPath(grid);
    return 0;
}