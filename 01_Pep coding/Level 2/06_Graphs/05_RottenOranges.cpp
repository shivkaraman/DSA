// https://leetcode.com/problems/rotting-oranges/description/
/*
0-representing an empty cell,
1-representing a fresh orange, or
2-representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

1. We push all rotten oranges to queue
2. We have to rottten all adjascent freash oranges, so we run BFS algo to do so
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int emptyCnt = 0;
        int rottenCnt = 0;
        //Pushing all rotten oranges on to queue
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) emptyCnt++; 
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        int nonEmptyCnt = grid.size() * grid[0].size() - emptyCnt;
        //Rotten oranges turns fresh oranges rotten in all 4 directions
        while(!q.empty()){
            int size = q.size();
            rottenCnt += size;
            if(rottenCnt == nonEmptyCnt) break;

            time++;
            for(int x = 0; x < size; x++){
                pair<int, int> p = q.front(); q.pop();

                int i = p.first;
                int j = p.second;

                if(i-1 >= 0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                }
                if(j+1 < grid[0].size() && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
                if(i+1 < grid.size() && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
            }
        }
        return rottenCnt == nonEmptyCnt ? time : -1;
    }
};

int main(){
    
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    Solution s;
    cout << s.orangesRotting(arr);
   
}