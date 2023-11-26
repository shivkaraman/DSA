// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

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
    int findMax(vector<int> &bloomDay){
        int mx = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            mx = max(mx, bloomDay[i]);
        }
        return mx;
    }



    int check(vector<int> &bloomDay, int day, int k){ //DRY RUN -> MUST
        int i = 0, n = bloomDay.size();
        int boque = 0;
        while(i < n){
            int kp1 = i + k;
            int cnt = 0;
            while(i < n && i < kp1){
                if(bloomDay[i++] > day)  break;
                cnt++;
            }
            if(cnt == k)
                boque++;
        }
        return boque;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = findMax(bloomDay);
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            int boqueCnt = check(bloomDay, mid, k);

            if(boqueCnt >= m){
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
    vector<int> arr ={ 7, 7, 7, 7, 12, 7, 7};
    Solution s;
    s.minDays(arr, 2,3);
    return 0;
}