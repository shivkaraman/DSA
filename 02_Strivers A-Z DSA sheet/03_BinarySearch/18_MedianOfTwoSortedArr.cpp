// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// https://www.youtube.com/watch?v=C2rRzz-JDk

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0, high = min(n1, n2);

        int n = n1 + n2;
        int leftHalf = n/2;
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = leftHalf - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1-1 < n1) l1 = nums1[mid1-1];
            if(mid2-1 < n1) l2= nums2[mid2-1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums1[mid2];

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 0) return max(l1, l2);
                else ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return -1;
    }
};

int main(){
    
    return 0;
}