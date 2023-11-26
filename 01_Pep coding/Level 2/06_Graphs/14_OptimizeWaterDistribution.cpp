/*
https://leetcode.ca/2019-02-10-1168-Optimize-Water-Distribution-in-a-Village/

wells-> 1 2 2

        u v wt
pipe -> 1 2 1
        2 3 1

Output-> 3
*/


// This problem can be rephrased that you are given V vertices and E edges  
// You are given an array wells in which wells[i] = cost of self loop
// You are given list of E edges called pipes where pipes[i] = [u, v, wt]
// You have to find the minimum spanning tree 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
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

int kruskalsAlgo(int V, vector<pair<int, pair<int, int>>> edges){
    DisjointSet ds(V);

    //Sorting edges according to weight
    sort(edges.begin(), edges.end());
    int mstWt = 0;
    int pipeCnt = 0;
    for (auto edge : edges) { 
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        //If there is no cycle -> consider the edge
        if (ds.findUPar(u) != ds.findUPar(v)) { //If the two nodes belong to different components => No cycle
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWt;
}

int minCostToSupplyWater(int n, vector<int>&wells, vector<vector<int>>& pipes){
    //vector<wt, u, v>
    vector<pair<int, pair<int, int>>> edges;
    //We introduce a dummy node 0 which acts like well and digging well in ith polt = edge between 0 and i
    for(int i = 1; i <= n; i++){
        edges.push_back({wells[i-1], {0, i}});
    }
    for(vector<int> &edge : pipes){
        edges.push_back({ edge[2], {edge[0], edge[1]}});
    }
    
    return kruskalsAlgo(n+1, edges);
}


int main(){
    int v,e;
    cin>>v>>e;
    
    vector<int>wells(v);
    for(int i=0;i<v;i++){
        cin>>wells[i];
    }
    
    vector<vector<int>>pipes(e,vector<int>(3));
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v, wells, pipes);
    
}