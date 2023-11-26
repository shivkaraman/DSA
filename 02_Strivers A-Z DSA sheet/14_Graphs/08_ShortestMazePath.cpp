// https://leetcode.com/problems/shortest-pathLen-in-binary-matrix/description/
/*
This is just dijkstras algorithm. But here we need not use PQ.
Reason: https://youtu.be/U5Mw4eyUmw4?si=BOnJHZ2iSHiJIM3U&t=401
*/
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
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); 
        if(grid[0][0] == 1|| grid[n-1][n-1] != 0) return -1;

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        int drow[] = {-1, 0, 1, 0, 1, -1, -1, 1};
        int dcol[] = {0, 1, 0, -1, 1, 1, -1, -1}; 

        while(!q.empty()){
            auto val = q.front();
            int row = val.first.first;
            int col = val.first.second;
            int pathLen = val.second;
            q.pop();

            if(row == n-1 && col == n-1) return pathLen;

            for(int idx = 0; idx < 8; idx++){
                int nr = row + drow[idx];
                int nc = col + dcol[idx];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && pathLen+1  < dist[nr][nc]){
                    grid[nr][nc] = -1;
                    dist[nr][nc] = pathLen+1;
                    q.push({{nr, nc}, pathLen+1});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,0,0,1,1},{0,1,0,0,1,0},{1,1,0,1,0,0},{0,1,0,0,1,1},{0,1,0,0,0,1},{0,0,1,0,0,0}};
    Solution n;
    cout << n.shortestPathBinaryMatrix(grid);
    return 0;
}