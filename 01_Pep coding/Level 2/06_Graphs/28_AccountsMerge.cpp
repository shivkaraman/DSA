// https://leetcode.com/problems/accounts-merge/description/
//This question involves grouping of account holders  

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

class disjointSet{
public:
    vector<int> parent;
    vector<int> rank;

    disjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void Union(int n1, int n2){
        int p1 = findUparent(n1);
        int p2 = findUparent(n2);

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }
        else{
            rank[p1]++;
            parent[p2] = p1;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        disjointSet ds(accounts.size());
        // map <acc, accHolder>
        map<string, int> mp;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string acc = accounts[i][j];
                //If the account already has an account holder, we merge the accounts
                if(mp.find(acc) != mp.end())
                    ds.Union(mp[acc], i);
                else
                    mp[acc] = i;
            }
        }
        vector<vector<string>> tempAns(accounts.size());
        for(auto &p : mp){
            int r = ds.findUparent(p.second);
            string acc = p.first;

            if(tempAns[r].size() == 0) tempAns[r].push_back(accounts[r][0]);
            tempAns[r].push_back(acc);
        }
        vector<vector<string>> ans;
        for(auto &vec : tempAns){
            if(vec.size() > 0)
                ans.push_back(vec);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}