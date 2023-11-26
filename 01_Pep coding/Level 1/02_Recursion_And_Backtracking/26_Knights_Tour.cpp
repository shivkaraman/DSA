// 1. You are given a number n, the size of a chess board.
// 2. You are given a row and a column, as a starting point for a knight piece.
// 3. You are required to generate the all moves of a knight starting in (row, col) such that knight visits 
//    all cells of the board exactly once.
// 4. Calculate and  print all configurations of the chess board representing the route
//    of knight through the chess board. Use sample input and output to get more idea.

// Note -> When moving from (r, c) there are possible 8 options.A knights move is in an “L-shape”—that is, they can move two squares 
// in any direction vertically followed by one square horizontally. Give first precedence to (r - 2, c + 1) and move in clockwise 
// manner to explore other options.

#include <iostream>
#include <vector>
using namespace std;

void displayBoard(vector<vector<int>> chess){
    for(int i = 0; i < chess.size(); i++){
        for(int j = 0; j < chess[0].size(); j++)
            cout << chess[i][j] << " ";
        cout<<endl;
    }
    cout<<endl;
}

void printKnightsTour(vector < vector <int> > chess, int row, int col,int move){
    if(row<0 || col<0 || row>= chess.size() || col>=chess.size() || chess[row][col]!=0)
        return;

    if(move ==chess.size()*chess.size()){
        chess[row][col]=move;
        displayBoard(chess);
        chess[row][col]=0;
        return;
    }
    chess[row][col]=move;
    printKnightsTour(chess,row-2,col+1,move+1);
    printKnightsTour(chess,row-1,col+2,move+1);
    printKnightsTour(chess,row+1,col+2,move+1);
    printKnightsTour(chess,row+2,col+1,move+1);
    printKnightsTour(chess,row+2,col-1,move+1);
    printKnightsTour(chess,row+1,col-2,move+1);
    printKnightsTour(chess,row-1,col-2,move+1);
    printKnightsTour(chess,row-2,col-1,move+1);
    chess[row][col]=0;
}

int main(){
    int n;
    cin>>n;
    vector < vector <int> > chess (n,vector<int>(n,0));
    int r,c;
    cin>>r>>c;
    printKnightsTour(chess,r,c,1);
    return 0;
}