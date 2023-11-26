//If an element if a matrix is 0, set all elements of the correso=ponding row and column as 0

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void setZero(vector<vector<int>> &vec){ //T = O(n*m) S=O(n)+O(m) => We can optimize the space complexity
    int n = vec.size(), m = vec[0].size();
    vector<bool> row(n, false);
    vector<bool> col(m, false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vec[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == true || col[j] == true){
                vec[i][j] = 0; 
            }
        }
    }
}

// Optimal https://youtu.be/N0MgLvceX7M?si=LnotHECZdQkacz-X&t=867
void setZero(vector<vector<int>> &vec){ //T = O(n*m) S=O(1) 
    int n = vec.size(), m = vec[0].size();
    
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vec[i][j] != 0) continue;

            vec[i][0] = 0;
            if(j == 0)
                col0 = 0;
            else
                vec[0][j] = 0;
        }
    }

    for(int i = n-1; i > 0; i--){
        for(int j = m-1; j > 0; j--){
            if(vec[i][0] == 0 || vec[0][j] == 0)
                vec[i][j] = 0;
        }
    }
    for(int j = m-1; j > 0; j--){
        if(vec[0][0] == 0)
            vec[0][j] = 0;
    }
    for(int i = n-1; i >= 0; i++){
        if(col0 == 0)
            vec[i][0] = 0;
    }
}


int main(){
    
    return 0;
}