/*
The approach is similar to the prevv question. Here we first identify the min of the softed half and findMin for min in the unsorted part
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
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mn = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            
            //Identifying the sorted half
            if(nums[low] <= nums[mid]) {//left half is sorted
                mn = min(mn, nums[low]);
                low = mid+1;
            }
            else {                //right half is sorted
                mn = min(mn, nums[mid]);
                high = mid-1;
            }
        }
        return mn;
    }
};

int main(){
    vector<int> vec = {4,5,6,7,0,1,2};
    Solution s;
    cout << s.findMin(vec);
    return 0;
}