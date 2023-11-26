/*
Given an array of N integets and a target, find unique quadraples a b c d such that
a + b + c + d = target
*/ 

#include<bits/stdc++.h>
using namespace std;

list<list<int>> twoSum (vector<int> &nums, int si, int ei, int target){
    sort(nums.begin(), nums.end());
    list<list<int>> ans;
    while(si < ei){
        int sum = nums[si] + nums[ei];
        if(sum < target) si++;
        else if(sum > target) ei--;
        else{
            ans.push_back(list<int> {nums[si], nums[ei]});
            si++;
            ei--;
            while(si < ei && nums[si] == nums[si-1]) si++;
            while(si < ei && nums[ei] == nums[ei-1]) ei--;
        }
    }
    return ans;
}

void createAns(list<list<int>> &smallAns, list<list<int>> &ans, int nums){
    for(list<int> v : smallAns){
        v.push_front(nums);
        ans.push_back(v);
    }
}

list<list<int>> threeSum(vector<int> &nums, int si, int ei, int target){
    list<list<int>> ans;
    for(int i = si; i < ei; i++){
        if(i != si && nums[i] == nums[i-1]) continue;

        list<list<int>> smallAns = twoSum(nums, i+1, ei, target-nums[i]);
        createAns(smallAns, ans, nums[i]);
    }
    return ans;
}

list<list<int>> fourSum(vector<int> &nums, int target){
    list<list<int>> ans;
    int si = 0, ei = nums.size()-1;
    for(int i = si; i < ei; i++){
        if(i != si && nums[i] == nums[i-1]) continue;

        list<list<int>> smallAns = threeSum(nums, i+1, ei, target-nums[i]);
        createAns(smallAns, ans, nums[i]);
    }
    return ans;
}



int main(){
    
}