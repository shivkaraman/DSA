/*
1. You are given a number n, representing the size of a n * n chess board.
2. You are required to calculate and print the permutations in which n queens can be placed on the 
   n * n chess-board. 

Sample Input

2

Sample Output
q1	q2
-	-


q1	-
q2	-


q1	-
-	q2


q2	q1
-	-


q2	-
q1	-


q2	-
-	q1


-	q1
q2	-


-	q1
-	q2


-	q2
q1	-


-	q2
-	q1


-	-
q1	q2


-	-
q2	q1
*/
#include<iostream>
#include<vector>
using namespace std;

//Permutation 2 for 2D array
void queenPermutation(vector<vector<int>> boxes, int boxi, int boxj, int qCount, vector<bool> visited){
    if(boxi == boxes.size()){
        if(qCount == boxes.size()){
            for(int i = 0; i < boxes.size(); i++){
                for(int j = 0; j < boxes.size(); j++){
                    if(boxes[i][j] == 0)
                        cout << "-";
                    else    
                        cout << "q" << boxes[i][j];
                    if(j == boxes.size()-1)
                        cout << endl;
                    else
                        cout << "\t";
                }
            }
            cout << "\n\n";
        }
        return;
    }
    int ni = boxi, nj = boxj+1;
    if(boxj == boxes.size() - 1){
        ni = boxi+1;
        nj = 0;
    }
    //Ayega to konsa queen ayega
    for(int i = 1; i <= boxes.size(); i++){
        if(visited[i-1] == false){
            boxes[boxi][boxj] = i;
            visited[i-1] = true;
            queenPermutation(boxes, ni, nj, qCount+1, visited);
            visited[i-1] = false;
            boxes[boxi][boxj] = 0;
        }
    }
    //queen nahi ayega
    queenPermutation(boxes, ni, nj, qCount, visited);
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> boxes(n, vector<int>(n,0));
    vector<bool> visited(n, false);
    queenPermutation(boxes, 0, 0, 0, visited);
}