// https://leetcode.com/problems/as-far-from-land-as-possible/description/
// This is similar to previous question, but here we have to find farthest 0 possible for all 1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(int i, int j, int n){
        return !(i == n || j == n || i < 0 || j < 0);
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue <pair<int, int>> q;
        //Pushing all 1's on queue
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = -1; //Marking visited
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        //BFS on all 1's to mark nearest 0 visited and find max dist
        int maxDist = 0, dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> p = q.front();
                q.pop();

                for(pair<int, int> x : dir){
                    int nr = p.first + x.first;
                    int nc = p.second + x.second;

                    if(isValid(nr, nc, grid.size()) && grid[nr][nc] == 0){
                        grid[nr][nc] = -1;  //Marking visited
                        maxDist = max(maxDist, dist);
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return maxDist == 0 ? -1  : maxDist;
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
    cout << s.maxDistance(arr);
    return 0;
}