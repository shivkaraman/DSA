/*
1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
2. You've an infinite supply of 2 * 1 tiles.
3. You are required to calculate and print the number of ways floor can be tiled using tiles.

Sample Input
8

Sample Output
34
*/

#include <iostream>
#include <vector> 
using namespace std ;

/*
h[i] -> No of ways in which tiles can be placed such that ith tile is a horizontal tile
v[i] -> No of ways in which tiles can be placed such that ith tile is a Vertical tile

Traverse and Solve-> 
    We can place tiles horizontally beside tiles of length i-2
    we can place tiles vertically beside ties of length i-1
*/
// int countWays(int n){
//     vector<int> h(n+1, 0);
//     vector<int> v(n+1, 0);
//     h[1] = 0;
//     v[1] = 1;
//     h[2] = v[2] = 1;
//     for(int i = 3; i <= n; i++){
//         h[i] = h[i-2] + v[i-2];
//         v[i] = h[i-1] + v[i-1];
//     }
//     return h[n] + v[n];
// }

int countWays(int n){
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        int h = dp[i-2];
        int v = dp[i-1];
        dp[i] = h+v;
    }
    return dp[n];
}

int main() {
    int n ;
    cin>>n ;

    cout << countWays(n);
}


