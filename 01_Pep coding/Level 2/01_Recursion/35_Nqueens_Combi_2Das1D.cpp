//Standard nqueen problem

#include<bits/stdc++.h>
using namespace std;
/*
This is also combination 2
Here we assime 2d array as 1d array of n*n size
Instead of passing 2 paramaters previ, prevj we just pass the cell no

*/
bool isQueenSafe(vector<vector<bool>> &cells, int row, int col){
    for(int r = row; r >= 0; r--){
        if(cells[r][col])
            return false;
    }
    for(int c = col; c >= 0; c--){
        if(cells[row][c])
            return false;
    }
    for(int r = row, c = col; r >= 0 && c >=0; r--, c--){
        if(cells[r][c])
            return false;
    }
    for(int r = row, c = col; r >= 0 && c <= cells.size(); r--, c++){
        if(cells[r][c])
            return false;
    }
    return true;
}

void nqueens(int queens , vector<vector<bool>> &cells , int lastCell){
   if(queens == cells.size()){
      for(int i = 0; i < cells.size(); i++){
         for(int j = 0; j < cells.size(); j++){
            if(cells[i][j] == false)
               cout << "-\t";
            else
               cout << "q\t";
         }
         cout << endl;
      }
      cout << endl;
      return;
   }
   for(int cell = lastCell+1; cell < cells.size()*cells.size(); cell++){
      int row = cell / cells.size();
      int col = cell % cells.size();
      if(isQueenSafe(cells, row, col)){
        cells[row][col] = true;
        nqueens(queens+1, cells, cell);
        cells[row][col] = false;
      }
   }
}
int main(){
    int n ;
    cin>>n ;
      
   vector<vector<bool>> chess(n , vector<bool>(n,false)) ;
   nqueens(0 , chess , -1) ;
}