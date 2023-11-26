/*
You are given an array n numbers.
You are given a number "tar"
You are required to calculate and print true or false, if there is a subset the elements of which add  up to "tar" or not.

https://www.youtube.com/watch?v=tRpkluGqINc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=11
*/

#include <bits/stdc++.h>
using namespace std;

void input(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }
}
/*
Storage-> 2D array of n+1 rows and target+1 cols
Meaning-> dp[i][j] -> Is there any subset with elements fron 0th idx -> ith idx which can sum up to value j
Traverse and Solve: 
Trivial case -> 
    The first row represents an empty array. The first cell in the first row (dp[0][0]) represents whether the empty array has 
    sum = 0 or not. An array has sum = 0, only the first cell will be true, rest all cells in the first row will be false. 
    The first column represents whether there is a subset with target = 0. Since every prefix array (array from index 0 to i) can have an empty subset whose target = 0, hence all cells in the first column can be marked as true.
Others-> 
    dp[i][j] -> We have a choice to include the ith element into the subset or not
    If subset till i-1th idx are already able to make sum=j, then we need not include the ith element
    If they are not able to sum up to j, we have to check if they sub up to j-(arr[i])

* We can put it like this
* If we are deciding if 4th player can bat or not (and desired score is x)
* 1. If the team of first 3 players are already able to make a score of x, we neeed not make the 4th player bat
* 2. If the team of first 3 player donot score x runs, we can further decide if the 4th player should bat or not
*        If the first 3 player hav their scores sum up = x-score[4th player] then we can make the 4th player bat coz
*        x-score[4th player]+score[4th player] = x
*/
void targetSumPair(vector<int> &arr, int target){
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(target + 1, false));
    dp[0][0] = 1;
    for(int i = 1; i < dp.size(); i++){
        for(int j = 0; j < dp[0].size(); j++){
            if(j == 0){ //0th col is always true because every array has an empty subset whose sum=0
                dp[i][j] = true;
            }
            else if(dp[i-1][j] == true){ //If subarray of i-1 elements already sum up to j
                dp[i][j] = true;
            }
            else{                        //Else we check if first i-1 elements sum up to j-arr[i]
                int val = arr[i-1];      
                if(j >= val && dp[i-1][j-val] == true){     
                    dp[i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < dp.size(); i++){
        if(dp[i][target] == true){
            cout << "true" << endl;
            return; 
        }
    }
    cout << "false" << endl;
}

int main(){
    int n, target;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    cin >> target;
    targetSumPair(vec, target);
    return 0;
}