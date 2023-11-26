/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of combinations of the n coins using which the 
     amount "amt" can be paid.

Note -> You have an infinite supply of each coin denomination i.e. same coin denomination can be used for many installments in payment of "amt"

https://www.youtube.com/watch?v=l_nR5X9VmaI&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=13
*/

#include <iostream>
#include <vector>
using namespace std;

// Meaning-> dp[i] -> No of combinations of coins that can be used to give change 'i'
// Direction-> 0-> Amt
int coinchangecombination(vector<int> coins, int tarAmt) {
    vector<int> dp(tarAmt + 1, 0);
    dp[0] = 1; // No of ways 0rs can be payed is 1(Give nothging)
    //* We are going coinwise because this is combination Eg if coins are {2,3,5,7} then when we go coinwise, 3 can come only after 2 and hence 32 is newer possible, ieif 23 is there 32 will never be there hence avoiding permutation
    for(int &coin : coins){ 
        for(int amt = coin; amt < dp.size(); amt++){
            dp[amt] += dp[amt - coin];
        }
    }
    return dp[tarAmt];
}

int main() {
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (int i = 0; i < coins.size(); i++) {
        cin >> coins[i];
    }
    int amt;
    cin >> amt;
   
    cout << coinchangecombination(coins, amt);
}