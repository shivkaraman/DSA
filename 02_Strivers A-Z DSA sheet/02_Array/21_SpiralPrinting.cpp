// https://leetcode.com/problems/spiral-matrix/description/

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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rs = 0, re = matrix.size()-1;
        int cs = 0, ce = matrix[0].size()-1;
        int round = 0;
        vector<int> ans;
        while(rs <= re && cs <= ce){
            if(round % 2 == 0){
                for(int j = cs; j <= ce; j++){
                    ans.push_back(matrix[rs][j]);
                }
                rs++;
                for(int i = rs; i <= re; i++){
                    ans.push_back(matrix[i][ce]);
                }
                ce--;
            }
            else{
                for(int j = ce; j >= cs; j--){
                    ans.push_back(matrix[re][j]);
                }
                re--;
                for(int i = re; i >= rs; i--){
                    ans.push_back(matrix[i][cs]);
                }
                cs++;     
            }
            round++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}