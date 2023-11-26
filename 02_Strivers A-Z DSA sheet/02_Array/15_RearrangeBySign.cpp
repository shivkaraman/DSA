/*
    Rearrange the elements of nums such that the modified array follows the given conditions:
    1. Every consecutive pair of integers have opposite signs.
    2. For all integers with the same sign, the order in which they were present in nums is preserved.
    3. The rearranged array begins with a positive integer.
    Return the modified array after rearranging the elements to satisfy the aforementioned conditions.
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

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(int num : nums){
            if(num < 0) neg.push_back(num);
            else pos.push_back(num);
        }
        int pi = 0, ni = 0, i = 0;
        while(pi < pos.size() && ni < neg.size()){
            if(i%2 == 0)
                nums[i++] = pos[pi++];
            else
                nums[i++] = neg[ni++];
        }
        while(pi < pos.size()){
            nums[i++] = pos[pi++];
        }
        while(ni < neg.size()){
            nums[i++] = neg[ni++];
        }
        return nums;
    }
};

int main(){
    
    return 0;
}