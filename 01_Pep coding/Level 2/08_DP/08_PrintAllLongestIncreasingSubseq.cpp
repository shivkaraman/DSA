#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Meaning-> dp[i] -> Longest increasing subsequence till ith number that ends with arr[i]
// direction-> 0->n
// 
// Why did we choose ending with arr[i] -> https://youtu.be/odrfUCS9sQk?t=704
void lis(vector<int> &arr, int n){
    vector<int> dp(n, 0);   
    dp[0] = 1;
    int ans = 1;

    for(int i = 1; i < n; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }

    queue<pair<int,string>> q;
    for(int i = 0; i < n; i++){
        if(dp[i] == ans) q.push({i, to_string(arr[i])});
    }

    while(!q.empty()){
        pair<int, string> p = q.front();
        q.pop();

        int idx = p.first;
        int num = arr[idx];
        int len = dp[idx];
        string substr = p.second;

        if(len == 1){
            cout << substr << endl;
        }
        for(int i = idx-1; i >= 0; i--){
            if(dp[i] == len-1 && arr[i] < num)  
                q.push({i, to_string(arr[i]) + " " + substr});
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];    
    }

    lis(arr, n);
    return 0;
}