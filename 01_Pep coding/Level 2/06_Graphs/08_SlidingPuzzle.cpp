// https://leetcode.com/problems/sliding-puzzle/description/
// https://www.youtube.com/watch?v=-7zxQzs3D2A&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=9
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string state;
        //Creating string from board
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                state.append(to_string(board[i][j]));
            }
        }
        string finSt = "123450";
        //Creating a swap list -> If idx is index of 0 in string then moves[idx] -> is the list of indexes of string currState wth which 0 can be swapped
        vector<vector<int>> moves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<string> visited;
        queue<string> q;
        q.push(state);

        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string curr = q.front();
                q.pop();

                if(curr == finSt) return cnt;                

                int idx;
                for(int i = 0; i < curr.size(); i++){
                    if(curr[i] == '0'){
                        idx = i;
                        break;
                    }
                }
                
                for(int move : moves[idx]){
                    swap(curr[idx], curr[move]);
                    if(visited.find(curr) != visited.end()){
                        swap(curr[idx], curr[move]);
                        continue;
                    } 
                    visited.insert(curr);
                    q.push(curr);
                    swap(curr[idx], curr[move]);
                }
            }
            cnt++;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> board(2, vector<int>(3));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> board[i][j];
        }
    }
    Solution s;
    cout << s.slidingPuzzle(board);
    return 0;
}