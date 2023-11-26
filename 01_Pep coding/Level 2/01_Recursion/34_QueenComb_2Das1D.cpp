/*
1. You are given a number n, representing the size of a n * n chess board.
2. You are required to calculate and print the combinations in which n queens can be placed on the 
    n * n chess-board. 

Sample Input
    2
Sample Output
    q	q	
    -	-	

    q	-	
    q	-	

    q	-	
    -	q	

    -	q	
    q	-	

    -	q	
    -	q	

    -	-	
    q	q
*/
#include<bits/stdc++.h>
using namespace std;
/*
This is also combination 2
Here we assime 2d array as 1d array of n*n size
Instead of passing 2 paramaters previ, prevj we just pass the cell no
*/

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
      cells[row][col] = true;
      nqueens(queens+1, cells, cell);
      cells[row][col] = false;
   }
}

int main(){
    int n ;
    cin>>n ;
      
   vector<vector<bool>> chess(n , vector<bool>(n,false)) ;
   nqueens(0 , chess , -1) ;
}