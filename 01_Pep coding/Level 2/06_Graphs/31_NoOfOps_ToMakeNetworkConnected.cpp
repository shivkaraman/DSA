
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
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void Union(int a, int b){
        int p1 = findUparent(a);
        int p2 = findUparent(b);     

        if(p1 == p2) return;
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
    //To make a graph of n vertices, n-1 edges are required
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet ds(n);
        int extra = 0;

        for(int i = 0; i < connections.size(); i++){
            for(int edge : connections[i]){
                if(ds.findUparent(i) == ds.findUparent(edge)) 
                    extra++;
                else
                    ds.Union(i, edge);
            }
        }

        int nc = 0; //No of conected components
        for(int i = 0; i < n; i++){
            if(ds.findUparent(i) == i)
                nc++;
        }

        return extra >= (nc-1) ? (nc-1) : -1;
    }
};

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> conn(v);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        conn[u].push_back(v);
    }
    Solution s;
    cout << s.makeConnected(v, conn);
    return 0;
}