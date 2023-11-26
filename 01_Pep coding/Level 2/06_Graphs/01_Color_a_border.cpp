/*
https://leetcode.com/problems/coloring-a-border/description/

You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location

You have to color the border of the connected component of element grid[row][col]

An element of the connected component is innernode if it is surrounded by nodes of connected component on all 4 directions
An element of the connected component is border if it is not surrounded by nodes of connected component on all 4 directions OR
if it is border of the grid

*/

#include<iostream>
#include<vector>
using namespace std;

/*
In the second condition, we are checking both for both -val and val coz
       r
        |
        v
        2   2
c1->  2 2 2 2
c2->  2 2 2 2
        2   2

Here grid[r][c1] and grid[r][c2] are inner elements
Say we first check if grid[r][c1] is inner element and make it inner element, the grid looks like

          r
          |
          v
         -2 -2
c1->  -2  2 -2 -2
c2->  -2 -2 -2 -2
         -2    -2

Now if we check if grid[r][c2] is inner element, we would get that it is a border element if we DONT CHECK  for grid[r-1][c2] != val

I am emphasising on this point coz most of the solutions on leetcode doesnot check for +ve value of val
*/
bool isBorder(vector<vector<int>>& grid, int r, int c, int val){
    //If it is border of grid, then it is border of connected compontnt
    if(r == 0 || r == grid.size()-1 || c == 0 || c == grid[0].size()-1) return true;
    
    //If element if surrounded by any other element other than value of itself, then it is a border (see discription above)
    if((grid[r][c+1] != -val && grid[r][c+1] != val) || (grid[r][c-1] != -val && grid[r][c-1] != val) || (grid[r+1][c] != -val && grid[r+1][c] != val) || (grid[r-1][c] != -val && grid[r-1][c] != val)) return true;

    return false;
}

//Here, we initially mark all nodes of the connected component as border element in preorder (by making it negative of itself)
//In post order, if the node is inner node, we undo the change
void DFS(vector<vector<int>> &grid, int r, int c, int val){
    if(r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] != val) return;

    grid[r][c] = -val;

    DFS(grid, r-1, c, val);
    DFS(grid, r, c+1, val);
    DFS(grid, r+1, c, val);
    DFS(grid, r, c-1, val);
    
    if(!isBorder(grid, r, c, val)) grid[r][c] = val;
    
}

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    DFS(grid, row, col, grid[row][col]);
    
    for(vector<int> &ROW : grid){
        for(int &val : ROW){
            if(val < 0) 
                val = color;
        }
    }
    return grid;
}

int main(){
    vector<vector<int>> vec = {{2,1,3,2,1,1,2},{1,2,3,1,2,1,2},{1,2,1,2,2,2,2},{2,1,2,2,2,2,2},{2,3,3,3,2,1,2}};

    colorBorder(vec, 4, 4, 3);
    for(vector<int> &ROW : vec){
        for(int &val : ROW){
            cout << val << " ";
        }
        cout << endl;
    }
}
 