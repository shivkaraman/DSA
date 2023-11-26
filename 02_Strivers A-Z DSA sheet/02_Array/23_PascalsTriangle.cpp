// https://leetcode.com/problems/pascals-triangle/

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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        for(int i = 1; i <= numRows; i++){
            vector<int> rowi;
            for(int j = 0; j < i; j++){
                if(j == 0 || j == i-1)
                    rowi.push_back(1);
                else
                    rowi.push_back(arr[i-2][j]+arr[i-2][j-1]);
            }
            arr.push_back(rowi);
        }
        return arr;
    }
};

int main(){
    
    return 0;
}