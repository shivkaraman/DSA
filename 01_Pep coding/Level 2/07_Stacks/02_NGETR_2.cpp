// NGETR in circular array 
// https://leetcode.com/problems/next-greater-element-ii/description/

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
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size());

        for(int i = nums.size()-1; i >= 0; i--){
            s.push(nums[i]);
        }
        
        for(int i = nums.size()-1; i >= 0; i--){
            int num = nums[i];
            while(!s.empty() && s.top() <= num){
                s.pop();
            }
            if(s.empty()){
                int nextg = -1;
                for(int j = 0; j < i; j++){
                    if(nums[j] > nums[i]){
                        nextg = nums[j];
                        break;
                    }
                }
                ans[i] = nextg;
            } 
            else ans[i] = s.top();

            s.push(num);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}