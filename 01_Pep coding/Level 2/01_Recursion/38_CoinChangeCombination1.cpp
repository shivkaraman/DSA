/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the combinations of the n coins (non-duplicate) using 
     which the amount "amt" can be paid.
    
Sample Input
    5
    2
    3
    5
    6
    7
    12

Sample Output
    2-3-7-.
    5-7-.
*/
#include <bits/stdc++.h>
using namespace std;

void coinChange(int i, vector<int>coins, int amtsf, int tamt, string asf){
    if(i==coins.size()){
        if(amtsf==tamt){
            cout<<asf<<"."<<endl;
        }
        return;
    }
    coinChange(i+1,coins,amtsf+coins[i],tamt,asf+to_string(coins[i])+"-");
    coinChange(i+1,coins,amtsf+0,tamt,asf);

}
int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amt;
    cin>>amt;
    coinChange(0, coins, 0, amt, "");
}