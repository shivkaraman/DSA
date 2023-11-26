// https://leetcode.com/problems/rotate-image/description/

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
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        //Taking transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
        //Swap rows
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                swap(arr[i][j], arr[i][n-j-1]);
            }
        }
    }
};

int main(){
    
    return 0;
}