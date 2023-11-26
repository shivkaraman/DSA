// https://leetcode.com/problems/validate-stack-sequences/description//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pushIdx = 0, popIdx = 0;
        int n = pushed.size();
        while(popIdx < n){
            while(s.empty() || popped[popIdx] != s.top()){
                if(pushIdx == n) return false;
                s.push(pushed[pushIdx++]);
            }
            s.pop();
            popIdx++;
        }
        return true;
    }
};



int main(){
    
    return 0;
}