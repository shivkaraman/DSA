// https://leetcode.com/problems/merge-intervals/

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
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        sort(arr.begin(), arr.end());
        ans.push_back(arr[0]);
        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= arr[i][0])
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            else
                ans.push_back(arr[i]);
                
        }
        return ans;
    }
};

int main(){
    
    return 0;
}