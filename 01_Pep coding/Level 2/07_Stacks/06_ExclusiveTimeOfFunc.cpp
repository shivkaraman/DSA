// https://leetcode.com/problems/exclusive-time-of-functions/description/

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

class mypair{
public:
    int id, st, ct;
    mypair(int i, int s, int c){
        id = i;
        st = s;
        ct = c; //Child process execution time
    }
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<mypair> s;
        for(string &log: logs){
            int id = stoi(log.substr(0, log.find(":")+1));
            string type = log.substr(log.find(":")+1, log.find_last_of(":")-log.find(":")-1);
            int t = stoi(log.substr(log.find_last_of(":")+1));

            if(type == "start"){
                s.push(mypair(id, t, 0));
            }
            else{   
                int st = s.top().st;
                int child = s.top().ct;
                s.pop();

                int interval = (t-st+1);
                ans[id] += (interval - child); 

                if(!s.empty()) //Updating parents child run time
                    s.top().ct += interval;
            }
        }
        return ans;
    }
};


int main(){
    int n;
    cin >> n;

    int size;
    cin >> size;
    vector<string> logs(size);

    for(int i = 0; i < size; i++){
        cin >> logs[i];
    }
    Solution s;
    vector<int> ans = s.exclusiveTime(n, logs);
    for(int i : ans)
        cout << i << " ";
    return 0;
}

