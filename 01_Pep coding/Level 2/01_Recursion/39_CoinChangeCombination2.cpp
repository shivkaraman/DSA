/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the combinations of the n coins (same coin can be used 
     again any number of times) using which the amount "amt" can be paid.
    
Sample Input
    5
    2 3 5 6 7
    12

Sample Output
    2-2-2-2-2-2-.
    2-2-2-3-3-.
    2-2-2-6-.
    2-2-3-5-.
    2-3-7-.
    2-5-5-.
    3-3-3-3-.
    3-3-6-.
    5-7-.
    6-6-.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void coinChange(int i, vector<int>&coins, int amtsf, int tamt, string asf) {
    if(i == coins.size()){
        if(amtsf == tamt)
            cout << asf << "." << endl;
        return;
    }
    //Le to kitni baar le
    for(int x = (tamt-amtsf)/coins[i]; x >= 1; x--){
        string temp = "";
        for(int y = 0; y < x; y++)
            temp += to_string(coins[i]) + "-";
        coinChange(i+1, coins, amtsf + x * coins[i], tamt, asf+temp);
    }
    //Na le
    coinChange(i+1, coins, amtsf, tamt, asf);
}

int main(){
    int n;
    cin>>n;

    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int amt;
    cin>>amt;

    coinChange(0, coins, 0, amt, "");
}