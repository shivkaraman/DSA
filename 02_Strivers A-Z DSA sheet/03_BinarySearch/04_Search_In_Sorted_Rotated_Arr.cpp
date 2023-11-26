/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
https://www.youtube.com/watch?v=5qGrJbHhqFs

Rotated sorted array => Identify sorted and unsorted half -> mazor paart
*/

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
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(nums[mid] == target)
                return mid;
            
            //Identifying the sorted half
            if(nums[low] <= nums[mid]) {//left half is sorted
                if(nums[low]  <= target && nums[mid] >= target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else {                //right half is sorted
                if(nums[mid] <= target && nums[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;

            }
        }
        return -1;
    }
};

int main(){
    vector<int> vec = {4,5,6,7,0,1,2};
    Solution s;
    cout << s.search(vec, 0);
    return 0;
}