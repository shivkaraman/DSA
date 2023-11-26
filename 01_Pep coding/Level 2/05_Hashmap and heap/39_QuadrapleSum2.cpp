#include<bits/stdc++.h>
using namespace std;

list<list<int>> fourSum(vector<int> &nums, int target){
    list<list<int>> ans;
    for(int i = 0; i < nums.size(); i++){
        while(i != 0 && nums[i] == nums[i-1]) continue;     

        for(int j = i+1; j < nums.size(); j++){
            while(j != (i+1) && nums[j] == nums[j-1]) continue;

            int si = j+1;
            int ei = nums.size()-1;

            while(si < ei){
                int sum = nums[i] + nums[j] + nums[si] + nums[ei];
                if(sum < target) si++;
                else if(sum > target) ei--;
                else{
                    ans.push_back(list<int> {nums[i], nums[j], nums[si], nums[ei]});
                    si++;
                    ei--;
                    while(si < ei && nums[si] == nums[si-1]) si++;
                    while(si < ei && nums[ei] == nums[ei-1]) ei--;
                }
            }
        }
    }
    return ans;
}



int main(){
    
}