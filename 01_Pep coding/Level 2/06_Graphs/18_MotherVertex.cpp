// Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
// Solution -> WE do a topological sort and the first element of the topological sort is the mother vertex

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

void DFS(vector<vector<int>> &graph, int node, vector<bool> &visited, stack<int> &s){
    visited[node] = true;
    for(int adj : graph[node]){
        if(!visited[adj])
            DFS(graph, adj, visited, s);
    }
    s.push(node);
}

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited, int &cnt){
    visited[node] = true;
    cnt++;
    for(int adj : graph[node]){
        if(!visited[adj])
            dfs(graph, adj, visited, cnt);
    }
}

int findMotherVertex(int n, vector<vector<int>> graph){
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(graph, i, visited, s);
        }
    }
    //Checking if the node is actually mother vertex
    int motherV = s.top();
    int cnt = 0;
    for(int i = 0; i < n; i++) visited[i] = false;
    dfs(graph, motherV, visited,cnt);

    return cnt == n ? motherV : -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
    cout << findMotherVertex(n,adjlist) << endl;
    return 0;
}

