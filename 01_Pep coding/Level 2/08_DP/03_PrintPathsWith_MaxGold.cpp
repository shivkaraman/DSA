/*
1. You are given a number n, representing the number of rows.
2. You are given a number m, representing the number of columns.
3. You are given n*m numbers, representing elements of 2d array a, which represents a gold mine.
4. You are standing in front of left wall and are supposed to dig to the right wall. You can start from any row in the left wall.
5. You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
6. Each cell has a value that is the amount of gold available in the cell.
7. You are required to identify the maximum amount of gold that can be dug out from the mine.
8. Also, you have to print all paths with maximum gold.

Sample Input
6 6
0 1 4 2 8 2
4 3 6 5 0 4
1 2 4 1 4 6
2 0 7 3 2 2
3 1 5 9 2 4
2 7 0 8 5 1

Sample Output
33
d3 d1 d2 d3 d1 

*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class myPair{
public:
    int i, j, cost;
    string s;
    myPair(int i, int j, string s){
        this->i = i; 
        this->j = j;
        this->s = s;
    }
};

/*
Meaning-> dp[i][j] -> Max fold that can be mined from current point to roght wall
Direction-> right wall -> left wall
Traverse and solve -> dp[i][j] = gold[i][j] + max(dp[i][j+1], max(dp[i-1][j+1], dp[i+1][j+1]));
                     We take a move which is max of all moves
*/

void maxCostPath(int n, int m, vector<vector<int>> &gold){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        dp[i][m-1] = gold[i][m-1];
    }

    //Minimum gold matrix
    for(int j = m-2; j >= 0; j--){
        for(int i = 0; i < n; i++){
            if(i == 0)
                dp[i][j] = gold[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
            else if(i == n-1)
                dp[i][j] = gold[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
            else
                dp[i][j] = gold[i][j] + max(dp[i][j+1], max(dp[i-1][j+1], dp[i+1][j+1])); 
        }
    }

    //BFS on cost matrix
    queue<myPair> q;
    q.push(myPair(0, 0, ""));
    for(int i = 1; i < n; i++){
        if(dp[i][0] > dp[q.front().i][q.front().j]){
            q.pop();
            q.push(myPair(i, 0, ""));        
        }
        else if(dp[i][0] == dp[q.front().i][q.front().j])
            q.push(myPair(i, 0, ""));        
    }

    cout << dp[q.front().i][q.front().j] << endl;
    while(!q.empty()){
        myPair mine = q.front();
        q.pop();

        int i = mine.i;
        int j = mine.j;
        string path = mine.s;

        if(j == m-1)
            cout << path << endl;
        else if(i == 0){
            int right = dp[i][j+1];
            int right_down = dp[i+1][j+1];

            if(right > right_down)
                q.push(myPair(i, j+1, path + "d2 "));
            else if(right_down > right)
                q.push(myPair(i+1, j+1, path + "d3 "));
            else{
                q.push(myPair(i, j+1, path + "d2 "));
                q.push(myPair(i+1, j+1, path + "d3 "));
            }
        }
        else if(i == n-1){
            int right = dp[i][j+1];
            int right_up = dp[i-1][j+1];

            if(right > right_up)
                q.push(myPair(i, j+1, path + "d2 "));
            else if(right_up > right)
                q.push(myPair(i-1, j+1, path + "d1 "));
            else{
                q.push(myPair(i, j+1, path + "d2 "));
                q.push(myPair(i-1, j+1, path + "d1 "));
            }
        }
        else{
            int right_up = dp[i-1][j+1];
            int right = dp[i][j+1];
            int right_down = dp[i+1][j+1];

            if(right > right_up && right > right_down)
                q.push(myPair(i, j+1, path + "d2 "));
            else if(right_up > right && right_up > right_down)
                q.push(myPair(i-1, j+1, path + "d1 "));
            else if(right_down > right && right_down > right_up)
                q.push(myPair(i+1, j+1, path + "d3 "));
            else{
                if(right_up == right && right == right_down){
                    q.push(myPair(i-1, j+1, path + "d1 "));
                    q.push(myPair(i, j+1, path + "d2 "));
                    q.push(myPair(i+1, j+1, path + "d3 "));
                }
                if(right == right_up){
                    q.push(myPair(i, j+1, path + "d2 "));
                    q.push(myPair(i-1, j+1, path + "d1 "));
                }
                else if(right == right_down){
                    q.push(myPair(i, j+1, path + "d2 "));
                    q.push(myPair(i+1, j+1, path + "d3 "));
                }
                else if(right_down == right_up){
                    q.push(myPair(i-1, j+1, path + "d1 "));
                    q.push(myPair(i+1, j+1, path + "d3 "));
                }
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> gold(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> gold[i][j];
        }
    }

    maxCostPath(n, m, gold);
    return 0;
}