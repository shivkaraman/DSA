/*
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are allowed to take one step left, right, up or down from your current position.
5. You can't visit a cell with 0 gold and the same cell more than once. 
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine if 
     you start and stop collecting gold from any position in the grid that has some gold.

Sample Input
    6
    6
    0 1 4 2 8 2
    4 3 6 5 0 4
    1 2 4 1 4 6
    2 0 7 3 2 2
    3 1 5 9 2 4
    2 7 0 8 5 1
Sample Output
    120
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
	
int goldMine(int sr, int sc, vector<vector<int>> gold, vector<vector<bool>> &visited){
    if(sr < 0 || sc < 0 || sr == gold.size() || sc == gold[0].size() || visited[sr][sc] == true || gold[sr][sc] == 0)
        return 0;
    visited[sr][sc] = true;
    int t = goldMine(sr-1, sc, gold, visited);
    int l = goldMine(sr, sc-1, gold, visited);
    int d = goldMine(sr+1, sc, gold, visited);
    int r = goldMine(sr, sc+1, gold, visited);
    return t + l + r + d + gold[sr][sc];
}
	
int main(){
	int n, m;
	cin >> n >> m;
	
    vector<vector<int>> gold(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> gold[i][j];
    }
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int mx{};
     for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(visited[i][j] != true && gold[i][j] != 0){
                int g = goldMine(i, j, gold, visited);
                mx = max(mx, g);
            }
        }
    }
    cout << mx << endl;
}   