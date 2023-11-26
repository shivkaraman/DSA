// https://leetcode.com/problems/132-pattern/description/
// https://www.youtube.com/watch?v=yL8a7nnb8xw


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
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int numsK = INT_MIN;

        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < numsK) return true; 
            while(!s.empty() && s.top() < nums[i]){ 
                //WKT in NGETR, when we pop any element in this loop, the element on top of stack is less than curr element =>  element on top is nums[k] and curr element is nums[j] => nums[k] < nums[j] 
                numsK = s.top();             
                s.pop();    
            }
            s.push(nums[i]); // now numsK = nums[k] and s.top() is nums[j]. In the next iteration, if nums[i] < numsK then we found the pattern
        }
        return false;
    }
};

int main(){
    
    return 0;
}