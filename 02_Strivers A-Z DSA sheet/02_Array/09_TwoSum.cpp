
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int rem = target - nums[i];
            if(mp.find(rem) == mp.end()) {
                mp[nums[i]] = i;
                continue;
            }
            ans.push_back(i);
            ans.push_back(mp[rem]);
            return ans;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}