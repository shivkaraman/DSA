#include<bits/stdc++.h>
using namespace std;

bool isQueenSafe(vector<vector<int>> &chess, int row, int col){
    for(int r = row; r >= 0; r--){
        if(chess[r][col] != 0)
            return false;
    }
    for(int r = row; r < chess.size(); r++){
        if(chess[r][col] != 0)
            return false;
    }
    for(int c = col; c >= 0; c--){
        if(chess[row][c] != 0)
            return false;
    }
    for(int c = col; c < chess.size(); c++){
        if(chess[row][c] != 0)
            return false;
    }
    for(int r = row, c = col; r >= 0 && c >=0; r--, c--){
        if(chess[r][c] != 0)
            return false;
    }
    for(int r = row, c = col; r < chess.size() && c < chess.size(); r++, c++){
        if(chess[r][c] != 0)
            return false;
    }
    for(int r = row, c = col; r >= 0 && c < chess.size(); r--, c++){
        if(chess[r][c] != 0)
            return false;
    }
    for(int r = row, c = col; r < chess.size() && c >= 0; r++, c--){
        if(chess[r][c] != 0)
            return false;
    }
    
    return true;
}

void nqueensPermutation(vector<vector<int>> &chess, int queen){
    if(queen > chess.size()){
        for(vector<int> &vec : chess){
            for(int &i : vec){
                if(i == 0)
                    cout << "-\t";
                else
                    cout << "q" << i << "\t";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int cell = 0; cell < chess.size() * chess.size(); cell++){
        int row = cell/chess.size();
        int col = cell%chess.size();
        if(chess[row][col] == 0 && isQueenSafe(chess, row, col)){
            chess[row][col] = queen;
            nqueensPermutation(chess, queen+1);
            chess[row][col] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> chess(n, vector<int>(n, 0));
    nqueensPermutation(chess, 1);
}