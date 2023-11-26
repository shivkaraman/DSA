// https://youtu.be/ZUFQfFaU-8U?si=TvJsrNtKJVuWs5QH&t=1386
/*
Why topo sort?
	Here we move from one node to another accroding to reachability.
	This minimizes the no of steps required to solve the problem. The time complexity of this algo is O(V+E) which is better than 
	O(V+E)log(V) of dijkstra.
*/
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

class Solution {
private:
    void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<int> &vis, stack<int> & s){
		vis[node] = 1;
		for (auto it: adj[node]) {
			int v = it.first;
			if (!vis[v]) 
				topoSort(v, adj, vis, s);
		}
		s.push(node);
	}
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> & edges) {
		vector <vector<pair<int, int>>> adj(N);
		for (int i = 0; i < M; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			adj[u].push_back({v, wt}); 
		}
		
		vector<int> vis(N, 0);
		stack<int> st;
		for (int i = 0; i < N; i++) {
			if (!vis[i]) {
				topoSort(i, adj, vis, st);
			}
		}

		vector<int> dist(N, 1e9);
		dist[0] = 0;
		while (!st.empty()) {
			int node = st.top();
			st.pop();

			for (auto &p : adj[node]) {
				int v = p.first;
				int wt = p.second;

				if (dist[node] + wt < dist[v]) {
					dist[v] = wt + dist[node];
				}
			}
		}

		return dist;
	}
};

int main() {
	int N = 6, M = 7;
	vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

	Solution obj;
	vector < int > ans = obj.shortestPath(N, M, edges);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}