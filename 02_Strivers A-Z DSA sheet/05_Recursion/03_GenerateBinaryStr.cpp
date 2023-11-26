// https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?leftPanelTab=2

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

vector<string> helper(int n){
    if(n == 1){
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }

    vector<string> nm1 = helper(n-1);
    vector<string> ansN;
    for(string s : nm1){
        if(s[s.size()-1] == '0'){
            ansN.push_back(s+'0');
            ansN.push_back(s+'1');
        }
        else
            ansN.push_back(s+'0');
    }   
    return ansN;
}

vector<string> generateString(int n){
    vector<string> ans = helper(n);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<string> ans = generateString(n);
    for(string &s : ans) cout << s << endl;
    return 0;
}