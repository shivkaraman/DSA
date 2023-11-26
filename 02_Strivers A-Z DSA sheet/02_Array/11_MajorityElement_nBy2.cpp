//Element with freq > n/2
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
    int majorityElement(vector<int>& nums) {
        int count = 0, ele;
        for(int num : nums){
            if(count == 0){
                ele = num;
                count = 1;
            }
            else if(ele == num)
                count++;
            else
                count--;
        }
        count = 0;
        for(int num: nums){
            if(num == ele) count++;
        }
        return ele;
    }
};

int main(){
    
    return 0;
}