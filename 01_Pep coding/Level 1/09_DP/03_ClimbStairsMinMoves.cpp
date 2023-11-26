/*
Sample Input 
    10 
    3 3 0 2 1 2 4 2 0 0
Sample Output
    4
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Meaning-> dp[i] contains min no of steps required from i to n
// Direction -> 0->n > n->n Which means we traverse from n->0
int cs(int arr[], int n) {
    vector<int> dp(n + 1, 0);
    dp[n] = 0; //No of moves from n->n is 0
    for(int i = n-1; i >= 0; i--){
        int m = INT_MAX;
        for(int j = 1; j <= arr[i]; j++){
            if(i + j < n){
                //If dp[i + j]=0, it means that there is no path from (i+j)th stair to nth stair
                if(dp[i + j] != 0)
                    m = min(m, dp[i + j]);
            }
            else if(i + j == n){
                m = 0;
                break;
            }
        }
        if(m != INT_MAX)
            dp[i] = m + 1;
    }
    return dp[0];
}
 
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0 ; i < n ; i++) {
    cin >> arr[i];
  }

  cout << cs(arr, n) << endl;
}