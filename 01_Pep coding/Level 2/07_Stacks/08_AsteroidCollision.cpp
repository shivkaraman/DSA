// https://leetcode.com/problems/asteroid-collision/description/

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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        //We are solving from n-1 to 0 to prevent reversing of answer at last 
        for(int i = asteroids.size()-1; i >= 0; i--){
            bool dontPush = false;
            //Asteroids can collide only when prev element moving forward and current element moving backward
            while(!s.empty() && s.top() < 0 && asteroids[i] > 0){
                dontPush = true;
                int a1 = abs(s.top());
                int a2 = abs(asteroids[i]);
                if(a2 > a1){
                    s.pop();
                    dontPush = false;
                }
                else {
                    if(a1 == a2)
                        s.pop();
                    break;
                }
            }
            if(!dontPush) s.push(asteroids[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main(){
    
    return 0;
}