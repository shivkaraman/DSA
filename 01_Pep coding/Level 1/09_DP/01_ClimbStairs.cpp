/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. In one move, you are allowed to climb 1, 2 or 3 stairs.
4. You are required to print the number of different paths via which you can climb to the top.

Sample Input
    4
Sample Output
    7

*/
#include <iostream>
#include <vector>
using namespace std;

// Expectation-> Give the no of paths from n->0
// Faith -> Function knows to give no of paths from (n-1)->0
/*
Without DP
int cs(int n){
    if(n == 0)
        return 1;
    if(n < 0)
        return 0;
    int nm1 = cs(n-1);
    int nm2 = cs(n-2);
    int nm3 = cs(n-3);
    int pc = nm1 + nm2 + nm3;   //Path count
    return pc;

}
*/
//Memorisation techneque
int cs(int n, vector<int> &qb){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(qb[n] != 0) return qb[n];
     
    int nm1 = cs(n-1, qb);
    int nm2 = cs(n-2, qb);
    int nm3 = cs(n-3, qb);
    int pc = nm1 + nm2 + nm3;   //Path count
    qb[n] = pc;
    return pc;

}
//Tabulation Technique
// Storage -> dp[n+1] and dp[i] -> No of paths from i to 0
// Direction -> Path from 0->0 is a smaller problem and 0->n is a bigger problem => TRAVEL AND SOLVE FROM 0 -> N
int csTabulation(int n){
    int *dp = new int[n + 1];
    dp[0] = 1; //0->0 janeka rasta ek hain ie chalo hi mat
    for (int i = 1;i <= n; i++){
        if(i == 1)
            dp[i] = dp[i- 1];
        else if(i == 2)
           dp[i] = dp[i - 1] + dp[i - 2];        
        else
            dp[i] = dp[i - 1] + dp[i-2] + dp[i-3];
    }   
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    //vector<int> qb(n+1, 0);
    //cout<<cs(n, qb)<<endl;
    cout << csTabulation(n) << endl;
}