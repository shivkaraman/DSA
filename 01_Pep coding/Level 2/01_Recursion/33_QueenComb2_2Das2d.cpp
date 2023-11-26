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

#include<iostream>
#include<vector>
using namespace std;

//Combination 2 for 2d array (instead of prev box , we use previ, prevj)
void queenCombination(vector<vector<bool>> boxes, int queen, int previ, int prevj){
    if(queen > boxes.size()){
        for(int i = 0; i < boxes.size(); i++){
            for(int j = 0; j < boxes.size(); j++){
                if(boxes[i][j] == false)
                    cout << "-\t";
                else
                    cout << "q\t";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    int i = previ, j = prevj+1;
    if(prevj == boxes.size()-1){
        i = previ+1;
        j = 0;
    }
    for(;i < boxes.size(); i++){
        for(;j < boxes.size(); j++){
            boxes[i][j] = true;
            queenCombination(boxes, queen+1, i, j);
            boxes[i][j] = false;
        }
        j = 0;//Because j has to be reinitialised to 0 after each row
    }
}
int main(){
    int n;
    cin >> n;

    vector<vector<bool>> boxes(n, vector<bool>(n, 0));
    queenCombination(boxes, 1, 0, -1);
}