// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

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
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] > target)
                j = mid-1;
            else if(nums[mid] < target)
                i = mid+1;
            else{
                first = mid;
                j = mid-1;
            }
        }
        int last = -1;
        i = 0, j = nums.size()-1;
        while(i <= j){
            int mid = (i+j)/2;
            if(nums[mid] > target)
                j = mid-1;
            else if(nums[mid] < target)
                i = mid+1;
            else{
                last = mid;
                i = mid+1;
            }
        }
        return {first, last};
    }
};

int main(){
    
    return 0;
}