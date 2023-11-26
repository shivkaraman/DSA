// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

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
    int maxDepth(string str) {
        if(str == "" || (str.size() == 1 && str[0] != '(' && str[0] != ')')) return 0;

        stack<char> s;
        int ans = 0;
        for(char ch : str){
            if(ch == '(')
                s.push('(');
            else if(ch == ')'){
                ans = max(ans, (int)s.size());
                s.pop();
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}