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

int dijkstra(unordered_map<int, vector<pair<int, int>>> &graph, vector<int> &nodes, int src, int dst){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    unordered_map<int, int> dist;
    for(int node : nodes) dist[node] = INT_MAX;
    dist[src] = 0;

    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();

        for(auto &adj : graph[node]){
            int adjNode = adj.first;
            int wt = adj.second;
            if(dist[node] + wt < dist[adjNode]){
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
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

    unordered_map<int, vector<pair<int, int>>> graph;
    int no_edges;
    cin >> no_edges;

    for(int i = 0; i < no_edges; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    int src;
    cin >> src;
    int dest;
    cin >> dest;

    cout << dijkstra(graph, nodes, src, dest);
    return 0;
}