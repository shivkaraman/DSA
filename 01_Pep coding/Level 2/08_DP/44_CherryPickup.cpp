// https://leetcode.com/problems/cherry-pickup/

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
    //Recursive Solution (Read the question, the answer is pretty self explainatory)
    int maxCherry = 0;
    void goUp(vector<vector<int>> &grid, int i, int j, int cherry){
        if(i < 0 || j < 0 || grid[i][j] == -1)
            return;
        
        if(i == 0 && j == 0){
            maxCherry = max(maxCherry, cherry);
            return;
        }
        
        int cherries = grid[i][j];
        grid[i][j] = 0;
        goUp(grid, i-1, j, cherry + cherries); //Up
        goUp(grid, i, j-1, cherry + cherries); //Left
        grid[i][j] = cherries;
    }

    void goDown(vector<vector<int>> &grid, int i, int j, int cherry){
        if(i >= grid.size() || j >= grid.size() || grid[i][j] == -1)
            return;
        
        if(i == grid.size()-1 && j == grid.size()-1){
            goUp(grid, i, j, cherry);
            return;
        }
        
        int cherries = grid[i][j];
        grid[i][j] = 0;
        goDown(grid, i+1, j, cherry + cherries); //Down
        goDown(grid, i, j+1, cherry + cherries); //Right
        grid[i][j] = cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        goDown(grid, 0, 0, 0);
        return maxCherry;
    }

    //Recursion optimisec approach + Memorization
    int goDown2(vector<vector<int>> &grid, int r1, int c1, int r2, int &n,vector<vector<vector<int>>> &dp){
        int c2 = r1+c1-r2;
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) return INT_MIN;

        //If both p1 and p2 reach destination
        if(r1 == n-1 && c1 == n-1)
            return grid[r1][c1];
        if(dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2];

        int cherries = 0;
        if(r1 == r2 && c1 == c2) //If both are on same cell => The cherry can be picked only once 
            cherries += grid[r1][c1];
        else
            cherries += grid[r1][c1] + grid[r2][c2];

        int m1 = goDown2(grid, r1, c1+1, r2, n, dp);   //1-> H & 2->H
        int m2 = goDown2(grid, r1+1, c1, r2+1, n, dp); //1-> V & 2->V
        int m3 = goDown2(grid, r1, c1+1, r2+1, n, dp); //1-> H & 2-> V
        int m4 = goDown2(grid, r1+1, c1, r2, n, dp);   //1-> V & 2-> H

        cherries += max(max(m1, m2), max(m3, m4));
        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup2(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(n, -1)));
        return max(0, goDown2(grid, 0, 0, 0, n, dp));
    }
};

int main(){
    
    return 0;
}
