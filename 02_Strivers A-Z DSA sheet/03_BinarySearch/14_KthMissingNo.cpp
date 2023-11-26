// https://leetcode.com/problems/kth-missing-positive-number/description/
// https://www.youtube.com/watch?v=uZ0N_hZpyps

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
    int findKthPositive1(vector<int>& arr, int k) { //Bruteforce
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= k)
                k++;
            else
                break;
        }
        return k;
    }

    int findKthPositive(vector<int>& arr, int k) {
        int n= arr.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            int missing = arr[mid]-(mid+1);

            if(missing < k)
                low = mid+1;
            else
                high = mid-1;
        }
        return high+1+k;
    }
};

int main(){
    
    return 0;
}