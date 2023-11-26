/*
1. You are given a number n, representing the count of coins.
2. You are given n numbers, representing the denominations of n coins.
3. You are given a number "amt".
4. You are required to calculate and print the number of permutations of the n coins using which the  amount "amt" can be paid.

Note1 -> You have an infinite supply of each coin denomination i.e. same coin denomination can be 
                  used for many installments in payment of "amt"
Note2 -> You are required to find the count of permutations and not combinations i.e.
                  2 + 2 + 3 = 7 and 2 + 3 + 2 = 7 and 3 + 2 + 2 = 7 are different permutations of same 
                  combination. You should treat them as 3 and not 1.

https://www.youtube.com/watch?v=yc0LunmJA1A&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=15
*/

#include <iostream>
#include <vector>
using namespace std;
// The only difference between permutation and combination is that 
// In combination we check only one coin at once(iterate over dp keeping coin same)
// But in permutation, we find permutation of each amt in dp at once(check for each
// coin for currunt amount)

// Meaning-> dp[i] -> No of permutations of coins summing upto amount i 
// Direction -> 0->Amt
  int CCP(vector<int> coins, int tarAmt, vector<int> dp) {
    dp[0] = 1; // No of ways 0 rs can be payed is 1(Give nothging)
    for(int amt = 1; amt <= tarAmt; amt++){
		for(int &coin : coins){
			if(amt - coin >= 0){
				int remAmt = amt - coin;
				dp[amt] += dp[remAmt];
			}
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
	vector<int> dp(amt + 1, 0);
	cout << CCP(coins, amt, dp);
}