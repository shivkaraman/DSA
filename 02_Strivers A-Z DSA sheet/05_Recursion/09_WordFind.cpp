// https://leetcode.com/problems/word-search/description/

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
    bool helper(vector<vector<char>>& board, int r, int c, string word, int idx, vector<vector<bool>> &visited){
        if(idx == word.size()) return true;
        if(r == board.size() || r < 0 || c == board[0].size() || c < 0 || visited[r][c] || board[r][c] != word[idx]) return false;
       
        visited[r][c]= true;
        if(helper(board, r, c+1, word, idx+1, visited)) return true;
        if(helper(board, r+1, c, word, idx+1, visited)) return true;
        if(helper(board, r, c-1, word, idx+1, visited)) return true;
        if(helper(board, r-1, c, word, idx+1, visited)) return true;
        visited[r][c]= false;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(helper(board, i, j, word, 0, visited)) return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    Solution s;
    s.exist(board, "ABCCED");
    return 0;
}