/*
1. You are given a matrix of 0's and 1's.
2. You have to find the maximum size square sub-matrix with all 1's.

Sample Input
5 6
0 1 0 1 0 1 
1 0 1 0 1 0 
0 1 1 1 1 0 
0 0 1 1 1 0 
1 1 1 1 1 1

Sample Output
3
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Storage-> mxn matrix
Meaning-> dp[i][j] -> largest square of 1s possible at point (i,j) given that pont (i,j) is the top left point of the square
Direction-> (n,m) is a smaller problem coz max size of square at (n,m) considering it as top-left point is 1
                     (0, 0) is the smaller problem
Traverse and solve-> 
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1], dp[i][j+1]) + 1
        This is because, current point ka neighbours me jo sabse chota square he, usko bada banne se jisne roka, vo hi currrent square ko bada bannese rokega

https://www.youtube.com/watch?v=UagRoA3C5VQ&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=1
*/
int largestSquareSubmatrix(int m, int n, vector<vector<int>> &vec){
    vector<vector<int>> dp(m, vector<int> (n, 0));
    int mx = 0;

    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(vec[i][j] == 0) continue;
            
            if(i == m-1 || j == n-1){
                dp[i][j] = vec[i][j];
            }
            else{
                int down = dp[i+1][j];
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];

                dp[i][j] = min(down, min(right, diag)) + 1;
            }
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int> (n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];

    cout << largestSquareSubmatrix(m, n, arr);
    return 0;
}