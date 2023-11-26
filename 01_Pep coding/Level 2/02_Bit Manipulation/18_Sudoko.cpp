#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>>& arr){
    
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}

void solveSudoku(vector<vector<int>> &arr,vector<int> &rows,vector<int> &cols,vector<vector<int>> &grid,int i,int j){

    if(i == arr.size()){
        display(arr);
        return ;
    }
    if(arr[i][j] > 0)
        solveSudoku(arr, rows, cols, grid, j == arr[0].size()-1 ? i+1 : i, j == arr[0].size()-1 ? 0 : j+1);
    else{
        for(int num = 1; num <= 9; num++){
            if( (rows[i] & (1 << num)) == 0 && (cols[j] & (1 << num)) == 0 && (grid[i/3][j/3] & (1 << num)) == 0){
                arr[i][j] = num;
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i/3][j/3] ^= (1 << num);

                solveSudoku(arr, rows, cols, grid, j == arr[0].size()-1 ? i+1 : i, j == arr[0].size()-1 ? 0 : j+1);

                arr[i][j] = 0;
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i/3][j/3] ^= (1 << num);
            }
        }
    }
    
}

int main(){
    
    vector<vector<int>>arr(9,vector<int>(9,0));
    vector<int>rows(9,0);
    vector<int>cols(9,0);
    vector<vector<int>>grid(3,vector<int>(3,0));
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int digit;
            cin>>digit;
            
            arr[i][j]=digit;
            rows[i] |= (1<<digit);
            cols[j] |= (1<<digit);
            grid[i/3][j/3] |= (1<<digit);
        }
    }
    
    solveSudoku(arr,rows,cols,grid,0,0);

}