// https://leetcode.com/problems/reverse-words-in-a-string/

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
    string reverseWords(string str) {
        stack<string> s;
        int i = 0, len = str.size();
        while(i < len){
            string word;
            while(i < len && str[i] == ' ') i++;
            while(i < len && str[i] != ' '){
                word.push_back(str[i++]);
            }
            if(word.size() > 0) s.push(word);
        }
        string ans;
        while(!s.empty()){
            ans.append(s.top());
            s.pop();
            if(s.size() >= 1)
                ans.push_back(' ');
        }
        return ans;
    }
};

int main(){
    
    return 0;
}