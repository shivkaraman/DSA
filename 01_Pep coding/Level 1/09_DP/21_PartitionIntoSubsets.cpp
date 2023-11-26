/*
1. You are given a number n, representing the number of elements.
2. You are given a number k, representing the number of subsets.
3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
E.g.
For n = 4 and k = 3 total ways is 6
12-3-4
1-23-4
13-2-4
14-2-3
1-24-3
1-2-34
*/

#include <iostream> 
#include <vector>
using namespace std ;

/*
Storage -> 2d matrix
Meaning-> dp[n][k] = No of ways to form k teams from n players
Traverse and solve-> 
        for dp[n][k], we have to options 
            1. Take team of n-1 players partitioned into k teams and put the curr player in any of the team 
            2. Take team of n-1 players partitioned into k-1 teams and create a new team (kth team) consisting of the
               player
*/
int countSubsets(int N, int K){
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    for(int n = 1; n <= N; n++){
        for(int k = 1; k <= K; k++){
            if(k == 1)  
                dp[n][k] = 1; //There is only one way to team n members into 1 team ie to include all of them
            else if(n < k) 
                dp[n][k] = 0;
            else if(n == k) 
                dp[n][k] = 1; //3 people can be arranged in 3 teams only in one way ie 1 member per team
            else{
                int nm1km1 = dp[n-1][k-1]; //There are K-1 teams, Kth team is curr player
                int nm1k = dp[n-1][k] * k; //There are already K teams, so curr player can join any of the team
                dp[n][k] = nm1k + nm1km1;
            }
        }
    }
    return dp[N][K];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << countSubsets(n, k);
    return 0;
}