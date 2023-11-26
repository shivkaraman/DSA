// https://www.youtube.com/watch?v=xvNwoz-ufXA

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

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0, count = 0;
        mp[0] = 1;
        for(int i = 0; i < arr.size(); i++){
            prefixSum += arr[i];
            count += mp[prefixSum-k];
            mp[prefixSum]++;
        }
        return count;
    }
};

int main(){
    
    return 0;
}