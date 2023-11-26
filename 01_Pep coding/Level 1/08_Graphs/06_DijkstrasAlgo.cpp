//Single source shortest path to all other nodes
// Drawback -> Dijkstras ALgorithm may not work for negative weighted edges
//How to detect negative edges -> After all edges are relaxed, relax one more time
#include <iostream>
#include <queue>
#include <stack>
#define INF 1e9
using namespace std;
  
// pair <dist , node>
typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int> > adj[], int u, int v, int wt){
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int, int> > adj[], int V, int src){
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq; //Min heap

	// Create a vector for distances and initialize all distances as infinite (INF)
	vector<int> dist(V, INF);

	// Insert source itself in priority queue and initialize its distance as 0.
	pq.push(make_pair(0, src));
	dist[src] = 0;

	// Looping till all distances are not finalized 
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		// Get all adjacent of u.
		for (auto x : adj[u]) {
			int v = x.first;
			int weight = x.second;

			// If there is shorted path to v through u.
			if (dist[u] + weight < dist[v]) {
				// Updating distance of v
				dist[v] = dist[u] + weight;
				pq.push({dist[v], v});
			}
		}
	}
	
	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

	

/*     40       2  
	0-------3------4
    |       |	   | \
  10|     10|     3|  \8
	|		|      |   \
 	1-------2      5----6
	    10           3
*/
int main() {
  	int V = 7;
    vector<iPair> adj[V];
  	addEdge(adj, 0, 1, 10);
  	addEdge(adj, 0, 3, 40);
  	addEdge(adj, 1, 2, 10);
  	addEdge(adj, 2, 3, 10);
  	addEdge(adj, 3, 4, 2);
  	addEdge(adj, 4, 5, 3);
  	addEdge(adj, 4, 6, 8);
  	
	shortestPath(adj, V, 0);
	return 0;
}