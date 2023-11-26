//Find the element whose frequency is greater than n/3

//Since the total no of elements is n and we need to find elements whose freqeuency is greater than n/3, there can be two answers ie 2 eleemnts whose freqeucny is greater than n/3
// https://youtu.be/vwZj1K0e9U8?si=tQVXbIEBH85MNNUe&t=914

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
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, ele1;
        int count2 = 0, ele2;
        for(int num : nums){
            if(count1 == 0 && num != ele2){
                ele1 = num;
                count1 = 1;
            }
            else if(count2 == 0 && num != ele1){
                ele2 = num;
                count2 = 1;
            }
            else if(ele1 == num)
                count1++;
            else if(ele2 == num)
                count2++;
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int num: nums){
            if(num == ele1) 
                count1++;
            else if(num == ele2) 
                count2++;
        }

        vector<int> ans;
        if(count1 > nums.size()/3)
            ans.push_back(ele1);

        if(count2 > nums.size()/3)
            ans.push_back(ele2);

        return ans;
    }
};

int main(){
    
    return 0;
}