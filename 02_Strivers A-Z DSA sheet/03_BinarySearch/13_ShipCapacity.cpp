
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
    int findSum(vector<int> &arr){
        int sum = 0;
        for(int num: arr){
            sum += num;
        }
        return sum;
    }

    bool findNoOfDays(vector<int> &weights, int cap, int days){
        int d = 1, sum = 0;
        for(int wt : weights){
            if(wt > cap) return false;
            
            if(sum + wt <= cap)
                sum += wt;
            else{
                sum = wt;
                d++;
                if(d > days)
                    return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1;
        int high = findSum(weights);
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            bool check = findNoOfDays(weights, mid, days);

            if(check){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {1,2,3,1,1};
    Solution s;
    s.shipWithinDays(arr, 4);
    return 0;
}