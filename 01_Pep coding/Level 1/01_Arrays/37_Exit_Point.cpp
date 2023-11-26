// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers (1's and 0's), representing elements of 2d array a.
// 4. Consider this array a maze and a player enters from top-left corner in east direction.
// 5. The player moves in the same direction as long as he meets '0'. On seeing a 1, he takes a 90 deg right turn.
// 6. You are required to print the indices in (row, col) format of the point from where you exit the matrix.
/*
0  0  1  0
1  0  0  0
0  0  0  0
1  0  1  0

output --> 1 3
*/
#include <iostream>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;

    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin>>arr[i][j];
    }

    int i=0,j=0;
    int direction=0;    
        
    while(true){
        direction = (direction + arr[i][j]) % 4;
        if(direction == 0)          //East
            j++;
        else if(direction == 1)     //South
            i++;
        else if(direction == 2)     //West
            j--;
        else if(direction == 3)     //North
            i--;
 
        if(i<0){
            i++;
            break;
        }
        else if(i==r){
            i--;
            break;
        }
        else if(j<0){
            j++;
            break;
        }
        else if(j==c){
            j--;
            break;
        }
    }
    cout<<i<<endl<<j;
    return 0;
}