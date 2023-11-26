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

    -	q1	
    q2	-	

    -	q1	
    -	q2	

    q2	-	
    q1	-	

    -	q2	
    q1	-	

    -	-	
    q1	q2	

    q2	-	
    -	q1	

    -	q2	
    -	q1	

    -	-	
    q2	q1	
*/
#include<iostream>
#include<vector>
using namespace std;

//Permutation 1 -> Instead of 1D boxes here we have 2D box
void queenPermutation(vector<vector<int>> boxes, int q){
    if(q > boxes.size()){
        for(vector<int> &vec : boxes){
            for(int &x : vec){
                if(x == 0)
                    cout << "-\t";
                else
                    cout << "q" << x << "\t";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < boxes.size(); i++){
        for(int j = 0; j < boxes.size(); j++){
            if(boxes[i][j] == 0){
                boxes[i][j] = q;
                queenPermutation(boxes, q+1);
                boxes[i][j] = 0;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> boxes(n, vector<int> (n, 0));
    queenPermutation(boxes, 1);
}