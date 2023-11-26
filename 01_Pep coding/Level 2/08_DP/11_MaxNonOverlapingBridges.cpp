/*
1. You are given a number n, representing the number of bridges on a river.
2. You are given n pair of numbers, representing the north bank and south bank co-ordinates of each bridge.
3. You are required to print the count of maximum number of non-overlapping bridges.

Sample Input
10
10 20
2 7
8 15
17 3
21 40
50 4
41 57
60 80
80 90
1 30

Sample Output
7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
This is just an application of Longest increasing subsequence 
Two bridges are non-overlaping if 
    1. north of first bridge > noth of second beidge and south of first > south of second OR 
    2. north of first bridge < noth of second beidge and south of first < south of second 
If we sort the brdges based on north coordinates and apply LIS on souch coordinate, we get the answer
WHY LIS ON ONLY SOUTH?
Because, since we already sorted the array based on north coordinate, we need not check north coordinate again. Current bridges north is already larger then all previous bridges
*/

int solution(vector<pair<int, int>> &bridges){
    sort(bridges.begin(), bridges.end());

    int n = bridges.size(), ans = 1;
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(bridges[i].second > bridges[j].second){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx+1;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> bridges(n);
    for(int i = 0; i < n; i++){
        cin >> bridges[i].first >> bridges[i].second;
    }

    cout << solution(bridges);
    return 0;
}