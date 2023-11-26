// https://www.youtube.com/watch?v=3gbO7FDYNFQ
// https://www.youtube.com/watch?v=1KRmCzBl_mQ&t=231s

#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  //Rank of all elements is initially zero
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) { 
            parent[i] = i;  //Initially, element is parent of itself => Size of each component is 1
            size[i] = 1;   
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); //Ultiate parent of u
        int ulp_v = findUPar(v); //Ultiate parent of y

        if (ulp_u == ulp_v) return;
        //Whoever has a smaller rank is connected to bigger rank => Bigger rank is the parent after union
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        //If rank is same, make anyone as parent, but here we increase the rank of the parent by 1
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int kruskalsAlgo(int V, vector<vector<int>> adj[]){
        // vector<weight, u, v>
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto edge : adj[i]) {
                int adjNode = edge[0];
                int wt = edge[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);

        //Sorting edges according to weight
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        cout << "U V WT" << endl;
        for (auto edge : edges) { 
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            //If there is no cycle -> consider the edge
            if (ds.findUPar(u) != ds.findUPar(v)) { //If the two nodes belong to different components => No cycle
                mstWt += wt;
                ds.unionBySize(u, v);
                cout << u << " " << v << " " << wt << endl;
            }
        }

        return mstWt;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto edge : edges) {
        vector<int> tmp(2);
        tmp[0] = edge[1];
        tmp[1] = edge[2];
        adj[edge[0]].push_back(tmp);

        tmp[0] = edge[0];
        tmp[1] = edge[2];
        adj[edge[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.kruskalsAlgo(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}
