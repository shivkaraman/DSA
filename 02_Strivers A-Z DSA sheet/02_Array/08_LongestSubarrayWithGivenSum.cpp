//Both positive elements and negative elements

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

int getLongestSubarray(vector<int>& arr, int k){
    unordered_map<int, int> mp;
    int n = arr.size();
    int sum = 0, mxLen = 0;
    for(int i = 0; i < n; i++){

        sum += arr[i];
        if(sum == k) mxLen = max(mxLen, i+1);

        auto it = mp.find(sum-k);
        if(it == mp.end())
            mp[sum] = i;
        else
            mxLen = max(mxLen, i-it->second);
    }
    return mxLen;
}

int main(){
    
    return 0;
}