// https://leetcode.com/problems/shortest-bridge/description/
// Shortest bridge is the minimum diatance between the two islands

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    queue <pair<int, int>> q;
    bool isValid(int i, int j, int n){
        return !(i == n || j == n || i < 0 || j < 0);
    }
    void dfs(vector<vector<int>> &grid, int i, int j){
        if(!isValid(i, j, grid.size())  || grid[i][j] == 0  || grid[i][j] == -1) return;

        grid[i][j] = -1;
        q.push({i, j});
        
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);   
    }

    int minDistance (vector<vector<int>>& grid){
        int dist = 1, minDist = INT_MAX;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();

                for(pair<int, int> &x : dir){
                    int nr = p.first + x.first;
                    int nc = p.second + x.second;

                    if(isValid(nr, nc, grid.size()) && grid[nr][nc] != -1){
                        if(grid[nr][nc] == 1){
                            minDist = min(minDist, dist-1);
                        }
                        else if(grid[nr][nc] == 0){
                            grid[nr][nc] = -1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
            dist++;
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false;
        //Marking first island and pushing all of them to queue
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        //Finding minimum distance between first and second island
        return minDistance(grid);
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>arr (n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    Solution s;
    cout << s.shortestBridge(arr);
    return 0;
}