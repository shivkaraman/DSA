// https://leetcode.com/problems/sort-characters-by-frequency/description/

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
    string frequencySort(string s) {
        unordered_map<char, int> map;
        for (char ch: s) map[ch]++;
        
        priority_queue<pair<int, char>> pq;
        for (auto pair: map) {
            pq.push({pair.second, pair.first});
        }

        string ans;
        pair<int, char> curr;
        while (!pq.empty()) {
            curr = pq.top();
            pq.pop();
            ans.append(curr.first, curr.second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    cout << s.frequencySort(str);
    return 0;
}