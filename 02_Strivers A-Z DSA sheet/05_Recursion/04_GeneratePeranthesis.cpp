// https://leetcode.com/problems/generate-parentheses/

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
    void helper(string s, int oc, int cc, vector<string> &ans, int n){
        if(oc > n || cc > n || cc > oc) return;
        if(oc == n && cc == n){
            ans.push_back(s);
            return;
        }
        if(oc == cc){
            string op = s;
            op.push_back('(');
            helper(op, oc+1, cc, ans, n);
        }
        else if(oc > cc){
            string op1 = s;
            op1.push_back('(');
            helper(op1, oc+1, cc, ans, n);
            string op2 = s;
            op2.push_back(')');
            helper(op2, oc, cc+1, ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("", 0, 0, ans, n);
        return ans;
    }
};

int main(){
    
    return 0;
}