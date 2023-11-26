
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
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
    
        queue<pair<int, int>> q;
        int orangeCnt = 0, rottenCnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0)
                    orangeCnt++;
                
                if(grid[i][j] == 2){
                    grid[i][j] = -2;
                    q.push({i, j});
                    rottenCnt++;
                }
            }
        }
        if(orangeCnt == 0) return 0;

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> node = q.front();
                q.pop();

                for(auto &p : dir){
                    int nr = node.first + p.first;
                    int nc = node.second + p.second;

                    if(nr == n || nc == m || nr < 0 || nc < 0 || grid[nr][nc] == -2 || grid[nr][nc] == 0)
                        continue;
                    grid[nr][nc] = -2;
                    q.push({nr, nc});
                    rottenCnt++;
                }
            }
            time++;
        }
        return rottenCnt == orangeCnt ? time-1 : -1;
    }
};

int main(){
    
    return 0;
}