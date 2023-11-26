// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMax(vector<int> &arr){
        int mx = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            mx = max(mx, arr[i]);
        }
        return mx;
    }
    bool checkRange(vector<int> &arr, int divisor, int threshold){
        int sum = 0;
        for(int num : arr){
            sum += ceil((double)num/divisor);
            if(sum > threshold)
                return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int low = 1;
        int high = findMax(arr);
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            bool check = checkRange(arr, mid, threshold);

            if(check){
                ans = check;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,5,9};
    Solution s;
    s.smallestDivisor(arr, 6);
    return 0;
}