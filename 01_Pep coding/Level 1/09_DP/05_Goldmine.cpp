/*
Your are given an nxm matrix where each element represents a gold mine.
You are standing in front of left wall and are supposed to dig to the right wall. You can start from  any row in the left wall.
You are allowed to move 1 cell right-up (d1), 1 cell right (d2) or 1 cell right-down(d3).
Each cell has a value that is the amount of gold available in the cell.
You are required to identify the maximum amount of gold that can be dug out from the mine.
*/

#include <bits/stdc++.h>
using namespace std;

//Meaning-> dp[i][j]-> Contains max gold that cam be mined from that block->right wall
//Direction-> We Traverse column by column -> [m-1]th col -> [0]th col
int collectGold(int n, int m, vector<vector<int>>& arr) {
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for(int j = m-1; j >=0; j--){
		for(int i = 0; i <n; i++){
		if(j == m-1)
			dp[i][j] = arr[i][j];
		else if (i == 0)
			dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i+1][j+1]);
		else if (i == n-1)
			dp[i][j] = arr[i][j] + max(dp[i][j+1], dp[i-1][j+1]);
		else
			dp[i][j] = arr[i][j] + max(dp[i-1][j+1], max(dp[i][j+1], dp[i+1][j+1]));
		}
	}
	int maxGold = INT_MIN;
	for(int i = 0; i < n; i++){
		if(dp[i][0] > maxGold)
		maxGold = dp[i][0];
	}
	return maxGold;
}



int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  cout << collectGold(n, m, arr);

}