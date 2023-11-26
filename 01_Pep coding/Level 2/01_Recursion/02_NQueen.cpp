/*
Sample Input
    4
Sample Output
    0-1, 1-3, 2-0, 3-2, .
    0-2, 1-0, 2-3, 3-1, .
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void nQueen(int n, int row,vector<bool> &col, vector<bool> &pd, vector<bool> &sd, string asf){
    if(row == n){
        cout << asf + "." << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        if(col[i] != true && pd[row + i] != true && sd[row-i+n-1] != true){
            col[i] = true;
            pd[row + i] = true; //row+col = principle diag
            sd[row - i + n - 1] = true;

            nQueen(n, row + 1, col, pd, sd, asf + to_string(row) + "-" + to_string(i) + ", ");

            col[i] = false;
            pd[row + i] = false; 
            sd[row - i + n - 1] = false; //row-col+(boardSize-1)
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<bool> col(n, 0);          //Column checker
    vector<bool> pd(2*(n-1), 0);     //Principal diagonal checker
    vector<bool> sd(2*(n-1), 0);     //Secondary diagonal checker
    nQueen(n, 0, col, pd, sd, "");
}