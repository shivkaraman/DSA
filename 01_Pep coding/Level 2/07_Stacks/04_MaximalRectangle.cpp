
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
    int largestRectangleAreaInHistogram(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;

        int ans = 0;
        for(int i = 0; i <= n; i++){
            int val = (i == n ? 0 : heights[i]);
            while(!s.empty() && heights[s.top()] >= val){
                int height = heights[s.top()];
                s.pop();
                int rb = i; //NSETR of s.top is current idx
                int lb = (!s.empty() ? s.top() : -1); //NSETL of s.top is next element in the stack

                ans = max(ans, height * (rb-lb-1));
            }
            s.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> histogram(matrix[0].size(), 0);
        //Creating histogram at each level
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1') 
                    histogram[j]++;
                else 
                    histogram[j] = 0;
            }
            ans = max(ans, largestRectangleAreaInHistogram(histogram));
        }
        return ans;
    }
};

int main(){
    
    return 0;
}