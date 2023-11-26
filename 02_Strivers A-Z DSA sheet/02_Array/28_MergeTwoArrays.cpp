// https://leetcode.com/problems/merge-sorted-array/

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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            for(int i = 0; i < n; i++){
                nums1[i] = nums2[i];
            }
            return;
        }
        int size = m+n;
        //Right align nums1 array
        for(int i = size-1; i >= n; i--){
            nums1[i] = nums1[i-n];
        }

        //Merge two array considering nums1 = nums1[n->size-1], nums2 = nums2, mergedArray = nums1
        int idx = 0;
        int i = n, j = 0;
        while(i < size && j < n){
            if(nums1[i] <= nums2[j])
                nums1[idx] = nums1[i++];
            else if(nums1[i] > nums2[j])
                nums1[idx] = nums2[j++];
            idx++;
        }
        while(i < size){
            nums1[idx++] = nums1[i++];
        }
        while(j < n){
            nums1[idx++] = nums2[j++];
        }
    }
};

int main(){
    vector<int> arr = {1,2,4,5,6,0};
    vector<int> arr2 = {3};
    Solution s;
    s.merge(arr, 5, arr2, 1);
    return 0;
}