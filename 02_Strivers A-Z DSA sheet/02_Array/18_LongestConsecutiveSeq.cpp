/*
You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.

    First, we will put all the array elements into the set data structure.
    If a number, num, is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set, we will check if x-1 exists inside the set. :
        If x-1 exists: This means x cannot be a starting number and we will move on to the next element in the set.
        If x-1 does not exist: This means x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.
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
    int longestConsecutive(vector<int>& nums) { 
        int mx = 0;
        unordered_set<int> s;
        for(int num : nums){
            s.insert(num);
        }
        for(int num: nums){
            if(s.find(num-1) == s.end()){
                int count = 1;
                int n = num+1;
                while(s.find(n) != s.end()){
                    count++;
                    n++;
                }
                mx = max(count, mx);
            }
        }
        return mx;
    }
};

int main(){
    
    return 0;
}