//https://leetcode.com/problems/koko-eating-bananas/description/

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
    int calcH(vector<int> &piles, int k, int h){
        int curr = 0;
        for(int i = 0; i < piles.size(); i++){
            curr += ceil((double)piles[i]/k);
            if(curr > h)
                return 1;
        }
        return 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1, high = piles[n-1];
        int ans = -1;

        while(low <= high){
            int k = (low+high)/2;
            int check = calcH(piles, k, h);

            if(check == 1) //currH >= h
                low = k+1;
            else {          //currH <=h
                ans = k;
                high = k-1;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {3,6,7,11};
    Solution s;
    cout << s.minEatingSpeed(arr, 8);
    return 0;
}