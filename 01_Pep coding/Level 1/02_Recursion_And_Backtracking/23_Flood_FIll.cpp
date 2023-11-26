// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner. 
//    Only four moves are allowed 't' (1-step up), 'l' (1-step left), 'd' (1-step down) 'r' (1-step right). You can only move 
//    to cells which have 0 value in them. You can't move out of the boundaries or in the cells which have value 1 in them 
//    (1 means obstacle)
// 5. Print all paths that can be used to move from top-left to bottom-right.
// Sample Input
//     0 0 1 0 1 0 
//     1 0 1 0 0 0 
//     1 0 0 0 1 0
//     1 0 1 0 1 0
//     1 0 0 0 0 0
// Smple output
//      rddddrrtttrrddd
//      rddddrrrr
//      rddrrtrrddd
//      rddrrddrr
//      rddrrddlluurruurrddd--> Invalid 

#include<iostream>
#include<vector>
using namespace std;

void floodfill(vector <vector<int>> maze,int row,int col,string ans,vector<vector<bool>> visited) {
    if(row == maze.size()-1 && col == maze[row].size()-1){
        cout<<ans<<endl;
        return;
    }
    if(row<0 || col<0 || row>maze.size()-1 || col>maze[row].size()-1 || maze[row][col]==1 || visited[row][col]==true)
        return;

    visited[row][col]=true;
    floodfill(maze,row-1,col,ans+"t",visited);
    floodfill(maze,row,col-1,ans+"l",visited);
    floodfill(maze,row+1,col,ans+"d",visited);
    floodfill(maze,row,col+1,ans+"r",visited);
    visited[row][col]=false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    vector < vector < bool >> visited(n, vector < bool > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];


    floodfill(arr,0,0,"",visited);
    return 0;
}