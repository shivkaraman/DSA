/*
1. You are given a number n, representing the count of items.
2. You are given n numbers, representing the values of n items.
3. You are given n numbers, representing the weights of n items.
3. You are given a number "cap", which is the capacity of a bag you've.
4. You are required to calculate and print the maximum value that can be created in the bag without overflowing it's capacity.
5. Also, you have to print the indices of items that should be selected to make maximum profit.
6. You have to print all such configurations.

Note -> Each item can be taken 0 or 1 number of times. You are not allowed to put the same item again and again.

Sample Input
5
15 14 10 45 30
2 5 1 3 4
7

Sample Output
75
45 30
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class myPair{
public:
    int i, j;
    string res;

    myPair(int i, int j, string res){
        this->i = i;    
        this->j = j;    
        this->res = res;
    }
};

void path_01napsack(int n, vector<int> &weight, vector<int> &value, int cap){
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= cap; j++){
            int wt = weight[i-1];
            int val = value[i-1];

            int exc = dp[i-1][j];
            int inc = val + (j >= wt ? dp[i-1][j-wt] : 0);

            dp[i][j] = max(inc, exc);
        }
    }

    cout << dp[n][cap] << endl;

    queue<myPair> q;
    q.push(myPair(n, cap, ""));
    while(!q.empty()){
        myPair p = q.front();
        q.pop();

        int i = p.i;
        int j = p.j; 
        string res = p.res;

        if(i == 0 || j == 0)
            cout << res << endl;
        else{
            if(dp[i][j] == dp[i-1][j])
                q.push(myPair(i-1, j, res+ " "));
            else    
                q.push(myPair(i-1, j-weight[i-1], to_string(value[i-1]) + " " + res + " "));
        }
    }
}

int main(){
    int n; 
    cin >> n;

    vector<int> val(n);
    for(int i = 0; i < n; i++)
        cin >> val[i];


    vector<int> wt(n);
    for(int i = 0; i < n; i++)
        cin >> wt[i];
    
    int cap;
    cin >> cap;

    path_01napsack(n, wt, val, cap);
    return 0;
}