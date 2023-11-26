// https://youtu.be/E9ziS6Fb2nw

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

// Prefix array implimentation
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftmax(n, -1);
        int mx = 0, idx = 0;
         for(int i = 0; i < n; i++){
            if(height[i] > mx){
                idx = i;
                mx = height[i];
            }
            leftmax[i] = idx;
        }
        vector<int> rightmax(n, -1);
        mx = 0, idx = n-1;
        for(int i = n-1; i >= 0; i--){
            if(height[i] > mx){
                idx = i;
                mx = height[i];
            }
            rightmax[i] = idx;
        }

        // Finding ans
        int ans = 0;
        for(int i = 0; i < n; i++){
            
            int lmax = leftmax[i];
            int rmax = rightmax[i];
            int ht = min(height[lmax], height[rmax])-height[i];

            ans += ht;
        }   
        return ans;
    }
};

// Stack implimentation -> Same strategy like HISTOGRAM AREA
class solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> s;
        for(int i = 0; i < height.size(); i++){
            while(!s.empty() && height[s.top()] < height[i]){
                int currHt = height[s.top()];
                s.pop();

                if(s.empty()) break;
                int lmax = s.top();
                int rmax = i;

                int width = rmax-lmax-1;
                int ht = min(height[lmax], height[rmax])-currHt; 
                ans += ht*width;
            }
            s.push(i);
        }
        return ans;
    }
};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    solution s;
    cout << s.trap(height);
    return 0;
}