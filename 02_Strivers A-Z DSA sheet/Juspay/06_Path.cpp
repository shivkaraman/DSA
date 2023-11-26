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

bool dfs(unordered_map<int, vector<int>> &graph, int node, int dest, unordered_map<int, bool> &visited, vector<int> &path){
    visited[node] = true;
    if(node == dest) return true;

    for(int adj : graph[node]){
        if(visited[adj]) continue;
        if(dfs(graph, adj, dest, visited, path)){
            path.push_back(adj);
            return true;
        }
    }
    return false;
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

    vector<int> path;
    bool check = dfs(graph, src, dest, visited, path);
    if(check){
        cout << src << " ";
        for(int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
    }
    else cout << -1;
    return 0;
}