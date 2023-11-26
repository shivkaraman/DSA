//Given a graph, source and dest node. Find the min no of edges the dest should break to avoid src from reaching it
//Print path from src to dest

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

void dfs(unordered_map<int, vector<int>> &graph, int node, int dest, unordered_map<int, bool> &visited, int &ans){
    visited[node] = true;
    if(node == dest){
        visited[node] = false;
        ans++;
        return;
    } 

    for(int adj : graph[node]){
        if(visited[adj]) continue;
        dfs(graph, adj, dest, visited, ans);
    }
}

int main(){
    int no_nodes;
    cin >> no_nodes;

    vector<int> nodes;
    for(int i = 0; i < no_nodes; i++){
        int node;
        cin >> node;
        nodes.push_back(node);
    }

    unordered_map<int, vector<int>> graph;
    int no_edges;
    cin >> no_edges;

    for(int i = 0; i < no_edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    cin >> src;
    int dest;
    cin >> dest;

    unordered_map<int, bool> visited;
    for(int i = 0; i < no_nodes; i++){
        visited[nodes[i]] = false;
    }

   int ans = 0;
   dfs(graph, src, dest, visited, ans);
   cout << ans;
    return 0;
}