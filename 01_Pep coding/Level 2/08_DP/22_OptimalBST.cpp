/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
https://www.youtube.com/watch?v=HnslzEs8dbY&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=26

You are given a two arrays
1. Nodes
2. No of times a perticular node is searched

Your task is to construct an optimal BST in which the no of operations to seacrh is minimized. Return the minimum operations
Input
    node : 10 12 20
    freq : 94 8 50
*/


#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> nodes, vector<int> freq){
    int n = nodes.size();
    vector<vector<int>> dp(n, vector<int> (n, 1e9));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = freq[i];
            }
            else{
                int freqSum = 0;
                for(int x = i; x <= j; x++){
                    freqSum += freq[x];
                }
                for(int k = i; k <= j; k++){
                    int left = k == i ? 0 : dp[i][k-1];
                    int right = k == j ? 0 : dp[k+1][j];
                    int curr = left + right + freqSum;

                    dp[i][j] = min(dp[i][j], curr);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin >> n;

    vector<int> nodes(n);
    vector<int> freq(n);
    for(int i = 0; i < n; i++){
        cin >> nodes[i];
    }
    for(int i = 0; i < n; i++){
        cin >> freq[i];
    }

    cout << solution(nodes, freq);
    return 0;
}