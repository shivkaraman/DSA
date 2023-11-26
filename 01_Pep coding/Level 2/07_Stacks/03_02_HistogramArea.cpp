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
    //* The apprpach is same but here we are calculating NGETR while calculating NGETL 
    void NSETL(vector<int>& heights, vector<int>& rb, vector<int>& lb){
        int n = heights.size();
        stack<int> s;

        s.push(0);
        for(int i = 1; i <n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                rb[s.top()] = i; //* NSETR of s.top is current element
                s.pop();
            }
            if(s.empty()) lb[i] = -1;
            else lb[i] = s.top();

            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rb(n, n) , lb(n, -1);
        NSETL(heights, rb, lb);

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
    vector<int> heights = {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(heights);
    return 0;
}