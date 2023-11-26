/*
You are given n*m matrix
You are standing in top-left cell and are required to move to bottom-right cell.
You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion.
Each cell has a value that will have to be paid to enter that cell (even for the top-left and bottom-right cell).
You are required to traverse through the matrix and print the cost of the path which is least costly.
Also, you have to print all the paths with minimum cost.

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
23
H V V H H V H V H V
H V V H H V H H V V
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class myPair{
public:
    int i, j;
    string s;
    myPair(int i, int j, string s){
        this->i = i; 
        this->j = j;
        this->s = s;
    }
};
/*
Meaning-> dp[i][j] -> Min cost of path from current point to dest point
Direction-> [n][m] -> [0][0]
Traverse and solve -> dp[i][j] = cost[i][j] + min(dp[i][j+1], dp[i+1][j]);   
                     We take a move which is minimum of horizontal and vertival move
*/
void minCostPath(int n, int m, vector<vector<int>> &maze){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    //Minimum cost matrix
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(i == n-1 && j == m-1)
                dp[i][j] = maze[i][j];
            else if(i == n-1)
                dp[i][j] = maze[i][j] + dp[i][j+1];
            else if(j == m-1)
                dp[i][j] = maze[i][j] + dp[i+1][j];
            else
                dp[i][j] = maze[i][j] + min(dp[i][j+1], dp[i+1][j]);   
        }
    }
    //BFS on cost matrix
    queue<myPair> q;
    q.push(myPair(0, 0, ""));
    while(!q.empty()){
        myPair p = q.front();
        q.pop();

        int i = p.i;
        int j = p.j;
        string s = p.s;

        if(i == n-1 && j == m-1)
            cout << s << endl;
        else if(i == n-1)
            q.push(myPair(i, j+1, s + "H"));
        else if(j == m-1)
            q.push(myPair(i+1, j, s + "V"));
        else{
            if(dp[i][j+1] == dp[i+1][j]){
                q.push(myPair(i, j+1, s + "H"));
                q.push(myPair(i+1, j, s + "V"));
            }
            else if(dp[i][j+1] < dp[i+1][j])
                q.push(myPair(i, j+1, s + "H"));
            else    
                q.push(myPair(i+1, j, s + "V"));
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }

    minCostPath(n, m, maze);
    return 0;
}