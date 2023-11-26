// https://leetcode.com/problems/trapping-rain-water/
// https://www.youtube.com/watch?v=PwEdhxQkFZs&list=PL-Jc9J83PIiE1_SifBEWRsD-fzxrvkja9&index=21

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size()-1;
        int lmax = 0, rmax = 0;
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                ans += lmax - height[l];
                l++;
            }
            else{
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}