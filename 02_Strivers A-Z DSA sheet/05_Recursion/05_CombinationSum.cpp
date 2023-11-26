// https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    void helper(vector<int> &candidates, int idx, vector<int> asf, int ssf, int target, set<vector<int>> &s){
        if(ssf == target){
            s.insert(asf);
            return;
        }
        if(ssf > target || idx == candidates.size()) return;
        
        int val = candidates[idx];
        if(ssf + val <= target){
            asf.push_back(val);
            helper(candidates, idx, asf, ssf+val, target, s);
            helper(candidates, idx+1, asf, ssf+val, target, s);
            asf.pop_back();
        }

        helper(candidates, idx+1, asf, ssf, target, s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> s;
        helper(candidates, 0, vector<int> {}, 0, target, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

int main(){
    
    return 0;
}