// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

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
    void Union(int p1, int p2){
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
    void keepType3First(vector<vector<int>>& edges){
        int idx = 0;
        for(int i = 0; i < edges.size(); i++){
            if(edges[i][0] == 3){
                swap(edges[i], edges[idx++]);
            }
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        disjointSet alice(n);
        disjointSet bob(n);
        int ans = 0;

        keepType3First(edges);

        //This is used to keep trak of no of elements in the component
        int asize = 1, bsize = 1;
        for(auto &edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];


            if(type == 1){
                int p1 = alice.findUparent(u);
                int p2 = alice.findUparent(v);
                // If Uparent of both the nodes are equal => They belong to same component => There already exists a path between u and v => WE CAN REMOVE THIS EDGE
                if(p1 == p2) ans++;
                //If parents are not equal => They belong to different components => Path doesnot exist 
                else{
                    alice.Union(p1, p2);
                    asize++;
                } 
            }
            else if(type == 2){
                int p1 = bob.findUparent(u);
                int p2 = bob.findUparent(v);
                if(p1 == p2) ans++;
                else{
                    bob.Union(p1, p2);
                    bsize++;
                }
            }
            else{
                int ap1 = alice.findUparent(u);
                int ap2 = alice.findUparent(v);
                int bp1 = bob.findUparent(u);
                int bp2 = bob.findUparent(v);

                if(ap1 == ap2 && bp1 == bp2) ans++;
                else {
                    alice.Union(ap1, ap2);
                    bob.Union(bp1, bp2);
                    asize++;
                    bsize++;
                }
            }
        }
        return asize == n && bsize == n ? ans : -1;
    }
};

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;
    for(int i = 0; i < e; i++){
        int type, u, v;
        cin >> type >> u >> v;
        edges.push_back({type, u, v});
    }
    Solution s;
    cout << s.maxNumEdgesToRemove(v, edges);
    return 0;
}

