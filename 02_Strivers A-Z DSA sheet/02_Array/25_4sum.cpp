//Extension of 3 sum approach

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
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;

        for(int idx = 0; idx < n; idx++){
            if(idx != 0 && arr[idx] == arr[idx-1]) continue;
            for(int i = idx+1; i < n; i++){
                if(i != idx+1 && arr[i] == arr[i-1]) continue;
                int j = i+1;
                int k = n-1; 

                while(j < k){
                    long long sum = arr[idx];
                    sum += arr[i];
                    sum += arr[j];
                    sum += arr[k];
                    
                    if(sum < target)
                        j++;
                    else if(sum > target)
                        k--;
                    else{
                        vector<int> temp = {arr[idx], arr[i], arr[j], arr[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j < k && arr[j] == arr[j-1]) j++;
                        while(j < k && arr[k] == arr[k+1]) k--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {2,2,2,2,2};
    Solution s;
    vector<vector<int>> ans = s.fourSum(arr, 8);
    for(auto v : ans){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}