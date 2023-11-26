// https://leetcode.com/problems/number-of-enclaves/description/
// We are asked to find the no of 1's jahase agar hum travel karna start karte ho, aur kitne bhi moves challo aap boundary cross nahi karpaoge. In sumple words, we are asked to find no of LAND components which doesnot have a cell on the boundaey of the grid

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int componentCount;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == 0 || grid[i][j] == -1) return;
        //If cell is on boundary of grid, mark it 
        if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1) componentCount = -1;

        //Marking as visited
        grid[i][j] = -1; 

        //If not boundary, increment component count
        if(componentCount != -1) componentCount++;

        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int num = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    componentCount = 0;
                    dfs(grid, i, j);
                    if(componentCount > 0) num += componentCount;
                }
            }
        }
        return num;
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    
    vector<vector<int>>arr(m,vector<int>(n));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    
    Solution s;
    cout<<s.numEnclaves(arr);
}