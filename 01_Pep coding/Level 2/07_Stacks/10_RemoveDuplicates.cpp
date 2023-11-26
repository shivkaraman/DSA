// https://leetcode.com/problems/remove-duplicate-letters/description/
// https://www.youtube.com/watch?v=_8WLoYLidTE

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
    string removeDuplicateLetters(string str) {
        vector<int> lastIdx(26,0);
        for(int i = 0; i < str.size(); i++){
            lastIdx[str[i]-'a'] = i;
        }
        vector<bool> visited(26, false);
        stack<char> s;
        
        for(int i = 0; i < str.size(); i++){
            int curr = str[i] - 'a';
            if(visited[curr]) continue;

            while(!s.empty() && s.top() > str[i] && lastIdx[s.top()-'a'] > i){
                visited[s.top()-'a'] = false;
                s.pop();
            }
            s.push(str[i]);
            visited[curr] = true;
        }

        string ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }   
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    
    return 0;
}