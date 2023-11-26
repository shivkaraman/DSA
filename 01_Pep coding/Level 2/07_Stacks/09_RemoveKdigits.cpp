/*
if the number is is decreasing monotone 998 or 98421 then delete the first k digits will make it smallest.right?

but if it is not decreasing monotone but increasing like 12345? than deleting last k element will make it smallest.

what for 123454? lets try deleting from left one by one
if we delete 1 than it 23454, oh it could have been lower if we put 1 at the beginning. okay lets keep one and delete 2 than it 13454, okay but it had a chance of being small if we can 2 at second positon and delete 3.

So the best would be to delete a number which has a smaller number on its right
Simply find a cliff which has a right side number smaller than it and delete it. do this recursively.

Still there is big thing missing
what you are doing everytime is when you find a number which is smaller than previous you remove previous and repeat.Got it ? you just have to create a increasing monotone stack of given num. if given number is already increasing monotone remove the last k elements
*/

// https://leetcode.com/problems/remove-k-digits/description/

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
    string removeKdigits(string num, int k) {
        if(num.size() == 1) return "0";
        stack<char> s;
        string ans;
        for(int i = 0; i < num.size(); i++){
            //We are removing top of every mountain created 
            while(!s.empty() && s.top() > num[i] && k > 0){
                s.pop();
                k--;
            }
            if(s.empty() && num[i] == '0') continue; //Prevents leading zero in ans
            s.push(num[i]);
        }
        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() == 0 ? "0" : ans;
    }
};

int main(){
    
    return 0;
}