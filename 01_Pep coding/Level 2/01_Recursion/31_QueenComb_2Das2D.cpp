/*
1. You are given a number n, representing the size of a n * n chess board.
2. You are required to calculate and print the combinations in which n queens can be placed on the 
    n * n chess-board. 
    Sample Input

Sample Input
    2
Sample Output
    qq
    --

    q-
    q-

    q-
    -q

    -q
    q-

    -q
    -q

    --
    qq

*/
#include<iostream>
#include<vector>
using namespace std;

/*
We use combination 1 approach
level - boxes
option - ayega ya nahi ayega

*/
void queenCombination(vector<vector<char>> boxes, int i, int j, int qCount){
    if(i == boxes.size()){
        if(qCount == boxes.size()){
            for(vector<char> &vec : boxes){
                for(char x : vec)
                    cout << x;
                cout << endl;
            }
            cout << endl;   
        }
        return;
    }
    int ni = i, nj = j+1;
    if(j == boxes.size()-1){
        nj = 0;
        ni = i+1;
    }
    if(qCount < boxes.size()){
        boxes[i][j] = 'q';
        queenCombination(boxes, ni, nj, qCount+1);
        boxes[i][j] = '-';
    }
    queenCombination(boxes, ni, nj, qCount);
}
int main(){
    int n;
    cin >> n;

    vector<vector<char>> boxes(n, vector<char> (n, '-'));
    queenCombination(boxes, 0, 0, 0);
    return 0;
}