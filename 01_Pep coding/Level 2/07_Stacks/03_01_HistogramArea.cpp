// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> NSETR(vector<int>& heights){
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n);

        ans[n-1] = n;
        s.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()) ans[i] = n;
            else ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }
    vector<int> NSETL(vector<int>& heights){
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n);

        ans[0] = -1;
        s.push(0);
        for(int i = 1; i <n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rb = NSETR(heights);
        vector<int> lb = NSETL(heights);

        int ans = 0;
        for(int i = 0; i < heights.size(); i++){
            int width = rb[i] - lb[i] -1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
};

int main(){
    vector<int> heights = {2, 1, 2};
    Solution s;
    cout << s.largestRectangleArea(heights);
    return 0;
}