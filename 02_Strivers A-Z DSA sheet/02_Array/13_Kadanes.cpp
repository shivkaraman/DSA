
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
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mxSum = INT_MIN;
        for(int num : nums){
            sum += num;
            mxSum = max(mxSum, sum);
            if(sum < 0) sum = 0;
        }
        return mxSum;
    }
};

int main(){
    
    return 0;
}