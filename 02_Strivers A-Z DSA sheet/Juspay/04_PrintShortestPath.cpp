//This was not asked by juspay but this is a code to print the shortest path from src to dest

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> printPath(vector<int> &parent ,int src, int dest){
    int node = dest;
    vector<int> path;
    while(node != src){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> dijkstra(vector<vector<int>> &graph, int src, int dest){
    vector<int> dist(graph.size(), INT_MAX);
    dist[src] = 0;

    vector<int> parent(graph.size());
    for(int i = 0; i < graph.size(); i++){
        parent[i] = i;
    }

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: graph[u]){
            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return printPath(parent, src, dest);
}

vector<int> shortestPath(vector<int> &edges, int n, int src, int dest){
    vector<vector<int>> graph(n); //Creating graph
    for(int i = 0; i < n; i++){
        if(edges[i] != -1){
            graph[i].push_back(edges[i]);
        }
    }

    return dijkstra(graph, src, dest);
}

int main(){
    int n;
    cin >> n;

    vector<int> edges(n);
    for(int i = 0 ; i < n; i++){
        cin >> edges[i];
    }

    int src, dest;
    cin >> src >> dest;

    vector<int> path = shortestPath(edges, n, src, dest);
    for(int node : path){
        cout << node << " ";
    }
    return 0;
}