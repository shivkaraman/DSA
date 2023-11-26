
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
    bool isPalindrome(string str){
        for(int i = 0; i < str.size()/2; i++){
            if(str[i] != str[str.size()-i-1]) return false;
        }
        return true;
    }
    void helper(string s, int idx, vector<string> &asf, vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(asf);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            string subs = s.substr(idx, i-idx+1);
            if(isPalindrome(subs)){
                asf.push_back(subs);
                helper(s, i+1, asf, ans);
                asf.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> asf;
        vector<vector<string>> ans;
        helper(s, 0, asf, ans);
        return ans;
    }
};

int main(){
    Solution s;
    s.partition("aab");
    return 0;
}