// https://leetcode.com/problems/redundant-connection/
// PROBLEM -> The added edge creates a cycle in the tree. So to find the redundant edge, we need to find the edge that is causing the cycle
// The edge that is to be removed is the edge that is forming a cycle, if there are multiple edges that are forming cycle, then e need to return the last one
// This questions involves adding edges dynamically => Disjoint Set

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


class DisjointSet {
public:
    vector<int> parent;
    vector<int> ranks;

    DisjointSet(int n){
        parent.resize(n);
        ranks.resize(n, 0);
        for(int i= 0; i < n; i++)
            parent[i] = i;
    }
    int findPar(int a) {
        if (a == parent[a])
            return parent[a];
        return parent[a] = findPar(parent[a]);
    }
    
    void Union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        
        if (ranks[a] >= ranks[b]) {
            parent[b] = a; 
            ranks[a]++;
        }
        else {
            parent[a] = b; 
            ranks[b]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size()+1);
        vector<int> ans;
        for(vector<int> &edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(ds.findPar(u) == ds.findPar(v)){
                ans = {u, v};
            }
            ds.Union(u, v);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}