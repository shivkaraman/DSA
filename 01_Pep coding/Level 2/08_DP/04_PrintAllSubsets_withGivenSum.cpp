/*
1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number "tar".
4. You are required to calculate and print true or false, if there is a subset the elements of which add up to "tar" or not.
5. Also, you have to print the indices of elements that should be selected to achieve the given target.
6. You have to print all such configurations.

Sample Input
5 
4 2 7 1 3
10

Sample Output
true
2 4 
1 2 3 
0 1 3 4 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class myPair{
public:
    int i, j;
    string substr;
    myPair(int i, int j, string substr){
        this->i = i;
        this->j = j;
        this->substr = substr;
    }
};

void TSS(int n, vector<int> &nums, int tar){
    vector<vector<bool>> dp(n+1, vector<bool>(tar+1, false));
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= tar; j++){
            if(j == 0)
                dp[i][j] = true;
            else if(dp[i-1][j] == true)
                dp[i][j] = true;
            else if(j >= nums[i-1] && dp[i-1][j-nums[i-1]])
                dp[i][j] = true;
        }
    }
    cout << boolalpha << dp[n][tar] << endl;

    if(!dp[n][tar]) return;

    queue<myPair> q;
    q.push(myPair(n, tar, ""));
    while(!q.empty()){
        myPair p = q.front();
        q.pop();

        int i = p.i;
        int j = p.j;
        string substr = p.substr;
        int val = nums[i-1];

        if(i == 0 && j == 0)
            cout << substr << endl;
        else{
            if(dp[i-1][j] == true)
                q.push(myPair(i-1, j, substr));
            if(j >= val && dp[i-1][j-val] == true)
                q.push(myPair(i-1, j-val, to_string(val) +substr));
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int tar;
    cin >> tar;

    TSS(n, nums, tar);
    return 0;
}