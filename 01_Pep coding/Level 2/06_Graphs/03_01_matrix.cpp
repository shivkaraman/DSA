// https://leetcode.com/problems/01-matrix/description/
/*
In this question, we have to find the nearest 0 to all the 1's

Instead of searching for nearest 0 for all the 1's, we follow a reverse approach
We find the 0's and make dist of the neighbors (in all 4 directions) as 1 (if the neighbour is a 1)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    
    bool isvalid(int i,int j,int m,int n){
        return !(i == m || j == n || j < 0 || i < 0);
    }
    
    vector<pair<int, int>> dir = {{1,0},{0,1},{0,-1},{-1,0}}; //Direction
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        //Creating a dist matrix and marking all 1's as unexplored
        vector<vector<int>> dis(m,vector<int>(n,-1));
        //Pushing all 0's to queue so that we can explore nearest 1 for each of them
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){ 
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            } 
        }  
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;
            for(auto &x : dir){
                int nr = r + x.first;  //next row
                int nc = c + x.second; //next col
                //If nr and nc are valid indices and unvisited
                if(isvalid(nr, nc, m, n) && dis[nr][nc] == -1){
                    q.push({nr, nc});
                    dis[nr][nc] = dis[r][c] + 1;
                }
            }
        }
        return dis;
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
    vector<vector<int>>ans = s.updateMatrix(arr);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}