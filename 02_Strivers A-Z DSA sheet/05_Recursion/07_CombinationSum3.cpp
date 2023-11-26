// https://leetcode.com/problems/combination-sum-iii/description/

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
    void helper(int k, int n, int prevNo, vector<int> &asf, vector<vector<int>> &ans){
        if(n < 0) return;
        if(k == 0){
            if(n == 0) ans.push_back(asf);
            return;
        }

        for(int i = prevNo+1; i <= 9; i++){
            asf.push_back(i);
            helper(k-1, n-i, i, asf, ans);
            asf.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> asf;
        helper(k, n, 0, asf, ans);
        return ans;
    }
};

int main(){
    
    return 0;
}