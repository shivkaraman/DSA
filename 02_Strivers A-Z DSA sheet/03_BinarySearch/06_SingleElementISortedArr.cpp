// https://leetcode.com/problems/single-element-in-a-sorted-array
/*
    Here we need to find a valid reason to justify the partition

    arr -> 1 1 2 2 3 3 4 5 5 6 6

        (1 1) (2 2) (3 3) 4 (5 5) (6 6)
         ^ ^   ^ ^   ^ ^     ^ ^   ^ ^
         | |   | |   | |     | |   | |
        (e,o) (e,o) (e,o)   (o,e) (o,e)
    
    So here we can can observe that on the left of single element left element has even index and right has odd indes for a repeated element and vice varsa on the right side of single element

    So we can say that 
        if curr index is even and the repeated element is present on the RIGHT  -> Single element is on right
        if curr index is even and the repeated element is present on the LEFT   -> Single element is on left

        if curr index is odd and the repeated element is present on the RIGHT  -> Single element is on left
        if curr index is odd and the repeated element is present on the LEFT   -> Single element is on right
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

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1, high = n-2;
    while(low <= high){
        int mid = (low+high)/2;

        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
            return nums[mid];

        if(mid % 2 == 0 && nums[mid] == nums[mid+1])
            low = mid+1;   
        if(mid % 2 == 0 && nums[mid] == nums[mid-1])
            high = mid-1;   

        if(mid % 2 != 0 && nums[mid] == nums[mid+1])
            high = mid-1;   
        if(mid % 2 != 0 && nums[mid] == nums[mid-1])
            low = mid+1;   
    }
    return -1;
}

int main(){
    
    return 0;
}