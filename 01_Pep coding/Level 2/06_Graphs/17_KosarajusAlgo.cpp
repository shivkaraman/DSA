// Find the number of Strongly connected components in the graph.

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

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s){
    visited[node] = true;
    for(int adj : graph[node]){
        if(!visited[adj]) dfs(adj, graph, visited, s);
    }
    s.push(node);
}

void revDfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
    visited[node] = true;
    for(int adj : graph[node]){
        if(!visited[adj]) revDfs(adj, graph, visited);
    }
}

int kosarajusAlgp(vector<vector<int>> graph, int v){
    stack<int> s;
    vector<bool> visited(v, false);
    //1. Random DFS
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            dfs(i, graph, visited, s);
        }
    }
    //2. Reversing all edges
    vector<vector<int>> revGraph(v);
    for(int i = 0; i < v; i++){
        visited[i] = false;
        for(int adj : graph[i]){
            revGraph[adj].push_back(i);
        }
    }
    // 3. DFS for reversed graph in the order of stack which we filled earlier
    int ans = 0;
    while(!s.empty()){
        int node = s.top();
        s.pop();

        if(!visited[node]){
            revDfs(node, revGraph, visited);
            ans++;
        }
    }
    return ans;
}

int main(){
    int v, e;      
    cin >> v >> e;

    vector<vector<int>> graph(v);
    for(int i = 0; i < e; i++){
        int u; cin >> u;
        int v; cin >> v;
        graph[u-1].push_back(v-1);
    }
    cout << kosarajusAlgp(graph, v);
    return 0;
}