//You are given a directed graph , src and destinationn
// You have to find the minimum number of edges you have to reverse in order to have atleast one path from vertex 1 to N, where the vertices are numbered from src to dest


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &graph, int u, int v){
    graph[u].push_back({v, 0});
    graph[v].push_back({u, 1}); //Reverse edge with cost 1
}

// Approach-> Just add a reverse edge with cost 1 and apply path from 
// src to dest using BFS and add cost at each step
int solution(vector<vector<pair<int, int>>> &graph, int src, int dest){
    list<pair<int, int>> q;
    q.push_back({src, 0});

    vector<bool> visited(graph.size(), false);
    while(q.size()){
        pair<int, int> node = q.front();
        q.pop_front();

        if(node.first == dest) return node.second;

        visited[node.first] = true;
        for(pair<int, int> &adj : graph[node.first]){
            if(visited[adj.first]) continue;

            if(adj.second == 0) q.push_front({adj.first, node.second});
            else q.push_back({adj.first, node.second + 1});
        }
    }
    return -1;
}   

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V+1);
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    int src, dest;
    cin >> src >> dest;
    cout << solution(graph, src, dest);
    return 0;
}