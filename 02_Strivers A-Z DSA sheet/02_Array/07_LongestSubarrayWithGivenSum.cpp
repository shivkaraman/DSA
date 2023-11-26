//Only positive elements

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int longestSubarrayWithSumK(vector<int> &arr, long long k) {
    int i = -1, j = -1;
    int sum = 0, n = arr.size();
    int ans = 0;
    while(true){
        bool flag1 = false, flag2 = false;
        while(i < n && sum <= k){
            if(sum == k)ans = max(ans, i-j);
            sum += arr[++i];
            flag1 = true;
        }

        while(j < i && sum > k){
            sum -= arr[++j];
            flag2 = true;
        }
        if(!flag1 && !flag2) break;
    }
    return ans;
}

int main(){
    
    return 0;
}