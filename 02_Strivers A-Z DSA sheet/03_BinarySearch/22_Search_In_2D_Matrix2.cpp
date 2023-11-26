// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c = m-1;
        while(r < n && c >= 0){
            int val = matrix[r][c];
            if(val == target)
                return true;
            else if(val < target)
                r++;
            else
                c--;
        }
        return false;
    }
};

int main(){
    
    return 0;
}