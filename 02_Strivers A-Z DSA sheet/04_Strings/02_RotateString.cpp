// https://leetcode.com/problems/rotate-string/description/

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
private: 
    bool rotateString(string A, string B, int rotation) {
        for(int i = 0; i < A.length(); i++) {
            if(A[i] != B[(i+rotation)%B.length()]) {
                return false;
            }
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) {
            return false;
        }
        if(s.length() == 0) {
            return true;
        }
        for(int i = 0; i < s.length(); i++) {
            if(rotateString(s, goal, i)) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}