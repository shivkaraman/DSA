
#include <iostream>
#include <vector>
using namespace std;
/*
https://www.youtube.com/watch?v=YzvF8CqPafI&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=24

We make use of cutting strategy itself, but here the storage and meaning is slightly different
storage & Meaning -> dp[i][j] = maximum valus that can be obtainied by bursting baloons i->j
            Eg -> 2 3 1 5 6 4
            dp[1][4] -> This would store max value obtained by bursting  3 1 5 6, BUT 3 1 5 6 ARE NOT IN COMPLETE ISOLATION
            BY THAT WE MEAN THAT MAX MONEY THAT CAN BE COLLECTED BY BURSTING 3 1 5 6 IN COMPLETE ARRAY 

        Simple example -> dp[1][1] -> Max money obtained by bursting baloon 3
            If we considered 3 is in isolation, the ans would be only 3
            but here we are not considering 3 in complete isolation, we are telling that dp[1][1] is money obtained by bursting 3 in complete array ie dp[1][1] = 2*3*1
        
Bursting options -> For each dp[i][j] ie subarray arr[i:j], we have options to burst any baloon
            say in subarr : 3 1 5 6 we have options to burst 3 OR 1 OR 5 OR 6
            WHILE BURSTING WE WILL CONSIDER IT TO BE BURST LAST AMONG ALL IN SUB ARRAY

                        0+       dp(3)+  dp(3,1)+  dp(3,1,5)+
LEFT+RIGHT+CURR      dp(1,5,6)+  dp(5,6)+  dp(6)+      0+
                       3*2*4     2*1*4   2*5*4      2*6*4
                          \        |      |       /
LAST TO BE BURST :    3 IS \  1 IS |      |5 IS  / 6 IS
                       LAST \ LAST |      |LAST /  LAST
                             \     |      |    /
                            --------------------
                        2   | 3    1     5    6 |  4
                            -------------------- 
*/
int solution(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            
            //Elements outside subarray (2 & 4 in the above example)
            int l = i == 0   ? 1 : arr[i-1];
            int r = j == n-1 ? 1 : arr[j+1];

            //Processing subarray
            for(int k = i; k <= j; k++){
                int left  = k == i ? 0 : dp[i][k-1];
                int right = k == j ? 0 : dp[k+1][j];
                int curr  = l * arr[k] * r;
                dp[i][j] = max(dp[i][j], left + right +curr);
            }   
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solution(arr) << endl;
    return 0;
}