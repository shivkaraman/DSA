/*
Sample Input
    4
Sample Output
    0-1, 1-3, 2-0, 3-2, .
    0-2, 1-0, 2-3, 3-1, .
*/
#include<iostream>
#include<string>
using namespace std;

bool isQueenSafe(int row, int col, int size, int cols, int pdiag, int sdiag){
    if((cols & (1 << col)) != 0)
        return false;
    if((pdiag & (1 << (row+col))) != 0)
        return false;
    if((sdiag &  (1 << (row-col + size-1))) != 0)
        return false;
    return true;
}
    
void solution(int size, int row, int cols, int pdiag, int sdiag, string asf) {

    if(row == size){
        cout << asf << "." << endl;
        return;
    }
    for(int col = 0; col < size; col++){
        if(isQueenSafe(row, col, size, cols, pdiag, sdiag)){
            cols = (cols ^ (1 << col));
            pdiag = (pdiag ^ (1 << (row+col)));
            sdiag = (sdiag ^ (1 << (row-col + size-1)));

            solution(size, row+1, cols, pdiag, sdiag, asf + to_string(row) + "-" + to_string(col) + ", ");

            cols = (cols ^ (1 << col));
            pdiag = (pdiag ^ (1 << (row+col)));
            sdiag = (sdiag ^ (1 << (row-col + size-1)));
        }
    }

}

int main() {
    int n;
    cin>>n;
    
    solution(n, 0, 0, 0, 0, "");
    // solution(boardSize, row, col, colMask, principalDiagonal mask, secondaryDiagonal mask, asf)
    return 0;
}