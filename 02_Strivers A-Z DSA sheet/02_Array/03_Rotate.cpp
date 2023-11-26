

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
    void reverse(vector<int> &arr, int si, int ei){
        for(int i = 0; i < (ei-si)/2; i++){
            swap(arr[si+i], arr[ei-i-1]);
        }
    }
    void rotate(vector<int> &arr, int k){
        int n = arr.size();
        k = k%n;
        reverse(arr, 0, n-k);
        reverse(arr, n-k, n);
        reverse(arr, 0, n);
    }
};

int main(){
    int n;  cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int k; cin >> k;

    Solution s;
    s.rotate(arr, k);
    for(int num : arr) cout << num << " ";
    return 0;
}