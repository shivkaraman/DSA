// https://leetcode.com/problems/01-matrix/

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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int dist = 1;
        vector<vector<int>> ans(n, vector<int> (m, 0));
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> node = q.front();
                q.pop();

                int r = node.first;
                int c = node.second;
                for(auto &p : dir){
                    int nr = r + p.first;
                    int nc = c + p.second;

                    if(nr == n || nc == m || nr < 0 || nc < 0) continue;

                    if(mat[nr][nc] == 1){
                        mat[nr][nc] = 0;
                        ans[nr][nc] = dist;
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}