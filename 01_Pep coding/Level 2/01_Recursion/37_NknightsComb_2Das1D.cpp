#include<bits/stdc++.h>
using namespace std;
/*
This is also combination 2
Here we assime 2d array as 1d array of n*n size
Instead of passing 2 paramaters previ, prevj we just pass the cell no

*/

bool isKnightSafe(vector<vector<bool>> &cells, int row, int col){
   if(row-2 >= 0 && col-1 >=0 && cells[row-2][col-1])
      return false;
   if(row-2 >= 0 && col+1 <= cells.size() && cells[row-2][col+1])
      return false;
   if(row-1 >= 0 && col+1 <= cells.size() && cells[row-1][col+2])
      return false;
   if(row-1 >= 0 && col-2 >=0 && cells[row-1][col-2])
      return false;
   return true;
}

void nknights(int queens , vector<vector<bool>> &cells , int lastCell){
   if(queens == cells.size()){
      for(int i = 0; i < cells.size(); i++){
         for(int j = 0; j < cells.size(); j++){
            if(cells[i][j] == false)
               cout << "-\t";
            else
               cout << "k\t";
         }
         cout << endl;
      }
      cout << endl;
      return;
   }
   for(int cell = lastCell+1; cell < cells.size()*cells.size(); cell++){
      int row = cell / cells.size();
      int col = cell % cells.size();
      if(isKnightSafe(cells, row, col)){
         cells[row][col] = true;
         nknights(queens+1, cells, cell);
         cells[row][col] = false;
      }
   }
}
int main(){
    int n ;
    cin>>n ;
      
   vector<vector<bool>> chess(n , vector<bool>(n,false)) ;
   nknights(0 , chess , -1) ;
}