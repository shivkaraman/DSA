// https://leetcode.com/problems/satisfiability-of-equality-equations/description/

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
    void Union(int a, int b){
        int p1 = findUparent(a);
        int p2 = findUparent(b);     
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
    bool equationsPossible(vector<string>& equations) {
        disjointSet ds(26); //coz 26 alphabets
        for(string &s : equations){
            int a = s[0]-'a';
            int b = s[3]-'a';
            char op = s[1];

            if(op == '=') ds.Union(a, b);
        }
        for(string &s : equations){
            int a = s[0]-'a';
            int b = s[3]-'a';
            char op = s[1];

            if(op == '!'){
                int p1 = ds.findUparent(a);
                int p2 = ds.findUparent(b);
                if(p1 == p2) return false;
            }
        }
        return true;
    }
};

int main(){
    int n;
    cin >> n;
    
    vector<string> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    Solution s;
    cout << s.equationsPossible(vec);
    return 0;
}