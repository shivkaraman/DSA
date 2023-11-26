// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
//At any moment of time, the NSETR of s.top is current index and NSETL of s.top is the 2nd element in stack

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
    //*In this approach we are finding area of rectangle formed by top element of the stack (Not each element of array as before)
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;

        int ans = 0;
        for(int i = 0; i <= n; i++){
            int val = (i == n ? 0 : heights[i]);
            while(!s.empty() && heights[s.top()] >= val){
                int height = heights[s.top()];
                s.pop();
                int rb = i; //* NSETR of s.top is current idx
                int lb = (!s.empty() ? s.top() : -1); //* NSETL of s.top is next element in the stack

                ans = max(ans, height * (rb-lb-1));
            }
            s.push(i);
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