// https://leetcode.com/discuss/interview-question/2032910/juspay-oa-nearest-meeting-cell

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

vector<int> dijkstra(vector<vector<int>> &graph, int src){
    vector<int> dist(graph.size(), INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: graph[u]){
            if(dist[u] + 1 < dist[v]){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}

int nearestMeeting(vector<int> &edges, int n, int c1, int c2){
    if(c1 == c2) return c1;
    if(edges[c1] == c2) return c2;
    if(edges[c2] == c1) return c1;

    vector<vector<int>> graph(n); //Creating graph
    for(int i = 0; i < n; i++){
        if(edges[i] != -1){
            graph[i].push_back(edges[i]);
        }
    }

    vector<int> dist1 = dijkstra(graph, c1);
    vector<int> dist2 = dijkstra(graph, c2);

    int mn = INT_MAX, node = -1;
    for(int i = 0; i < n; i++){
        if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;

        int dist = dist1[i]+dist2[i];
        if(dist < mn){
            mn = dist;
            node = i;
        }
    }
    return node;
}

int main(){
    int n;
    cin >> n;

    vector<int> edges(n);
    for(int i = 0 ; i < n; i++){
        cin >> edges[i];
    }

    int c1, c2;
    cin >> c1 >> c2;

    cout << nearestMeeting(edges, n, c1, c2);
    return 0;
}