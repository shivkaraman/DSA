/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without 
    overflowing it's capacity.
Note -> Each item can be taken any number of times. You are allowed to put the same item again 
        and again.      
*/

#include <iostream>
#include <vector>
using namespace std;

// Each item can be taken any no of times => DUPLICACY is allowed => 1D array
// Also in this question, order of the items doesnot matter => COMBINATION => AYEGA ya NAHI AYEGA
// Meaning -> dp[i] : max value that can be obtained if capacity was i
// Direction-> 0->n
void unboundedKnapsack(int n,vector<int> value, vector<int> weight,int capacity){
    vector<int> dp(capacity+1, 0);
    for(int i = 0; i < n; i++){
        int wt = weight[i];
        int val = value[i];
        for(int cap = 1; cap <= capacity; cap++){
            if(cap >= wt){
                dp[cap] += max(dp[cap], val + dp[cap-wt]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    int cap;
    cin >> cap;
    
    unboundedKnapsack(n,val, weight,cap);
}