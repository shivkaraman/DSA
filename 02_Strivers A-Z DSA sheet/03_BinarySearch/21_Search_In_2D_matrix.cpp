// https://leetcode.com/problems/search-a-2d-matrix/

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
        int low = 0, high = n*m-1;
        while(low <= high){
            int midCell = (low+high)/2;
            int row = midCell/m;
            int col = midCell%m;

            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                low = midCell+1;
            else
                high = midCell-1;
        }
        return false;
    }
};

int main(){
    
    return 0;
}