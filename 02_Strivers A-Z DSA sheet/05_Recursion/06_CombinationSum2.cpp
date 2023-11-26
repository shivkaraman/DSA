// https://leetcode.com/problems/combination-sum-ii/description/
// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/

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
    void findCombination(int idx, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& asf ){
        if(target==0){
            ans.push_back(asf);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            asf.push_back(candidates[i]);
            findCombination(i+1,target-candidates[i],candidates,ans,asf);
            asf.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> atomic_signal_fence;
        findCombination(0,target,candidates,ans,atomic_signal_fence);
        return ans;
    }
};

int main(){
    
    return 0;
}