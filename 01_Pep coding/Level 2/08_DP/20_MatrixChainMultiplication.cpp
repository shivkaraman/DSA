// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
/*
    a b c  a d
    d e f  b e
           c f
    2x3 3x2
    Reslutant = 2x2
    No of operations in multiplying two matrices of order axb and bxc = a*b*c

*/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr){
    int n = arr.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0)
                dp[i][j] = 0;
            else if(g == 1)
                dp[i][j] = arr[i] * arr[i+1] * arr[i+2];
            else{
                for(int k = i; k < j; k++){ 
                    //dp -> left half: i, k    right half: k+1  j
                    //arr-> left half: i, k+1  right half: k+1  j+1
                    int left = dp[i][k];    
                    int right = dp[k+1][j]; 
                    int currCost = arr[i] * arr[k+1] * arr[j+1];
                    dp[i][j] = min(dp[i][j], left+right+currCost);
                }
            }
        }
    }
    return dp[0][n-1];
}
int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << solution(arr);
    return 0;
}