
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
    void dfs(vector<vector<char>> &board, int n, int m, int i, int j, char val){
        if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] == 'X' || board[i][j] == val) return;

        board[i][j] = val;
        dfs(board, n, m, i+1, j, val);
        dfs(board, n, m, i, j+1, val);
        dfs(board, n, m, i-1, j, val);
        dfs(board, n, m, i, j-1, val);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();

        //Leftmost and rightmost row
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                dfs(board, n, m, i, 0, '-');
            if(board[i][m-1] == 'O')    
                dfs(board, n, m, i, m-1, '-');
        }

        //Top and botttom column
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O')
                dfs(board, n, m, 0, j, '-');
            if(board[n-1][j] == 'O')    
                dfs(board, n, m, n-1, j, '-');
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    dfs(board, n, m, i, j, 'X');
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
};

int main(){
    vector<vector<char>> arr = {{'X','O','X','O','X','O'},
                                {'O','X','O','X','O','X'},
                                {'X','O','X','O','X','O'},
                                {'O','X','O','X','O','X'}};
    Solution s;
    s.solve(arr);
    return 0;
}