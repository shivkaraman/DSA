// https://leetcode.com/problems/remove-outermost-parentheses/

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
    string removeOuterParentheses(string str) {
        stack<char> s;
        string ans;
        bool firstChar = true;
        for(char ch : str){
            if(ch == '('){
                if(!firstChar) ans.push_back(ch);
                s.push(ch);
                firstChar = false;
            } 
            else{
                if(s.size() == 1) 
                    firstChar = true;
                else 
                    ans.push_back(')');
                s.pop();
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}