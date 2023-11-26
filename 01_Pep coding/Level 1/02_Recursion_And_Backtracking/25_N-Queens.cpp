// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
//    Note - Queens kill at distance in all 8 directions
// 3. Calculate and print all safe configurations of
//  n-queens. Use sample input and output to get more idea.
// Sample Input
// 4
// Sample Output
// 0-1, 1-3, 2-0, 3-2, .
// 0-2, 1-0, 2-3, 3-1, .
//      0 1 0 0              0 0 1 0
//      0 0 0 1              1 0 0 0
//      1 0 0 0              0 0 0 1
//      0 0 1 0              0 1 0 0

#include <iostream>
#include <vector>
using namespace std;

bool isQueenSafe(vector<vector<int>> chess, int row, int col){
    for(int i=row-1; i>=0; i--){                                    //Colums check
        if(chess[i][col]==1)
            return false;
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){               //Principle diagonal check
        if(chess[i][j]==1)
            return false;
    }
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){     //Secondary diagonal check
        if(chess[i][j]==1)
            return false;
    }
    return true;
}

void printNqueens(vector <vector<int>> chess, string qsf,int row){
    if(row==chess.size()){
        cout<<qsf+"."<<endl;
        return;
    }
    for(int col=0; col<chess[0].size(); col++){
        if(isQueenSafe(chess,row,col)){
            chess[row][col]=1;
            printNqueens(chess, qsf+to_string(row)+"-"+to_string(col)+ ", ", row+1);
            chess[row][col]=0;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> chess(n,vector<int>(n));
    printNqueens(chess,"",0);
    return 0;
}