/*
This can be used for negative weighted graphs

Relaxation means->
        Say u and v are two vertices with weight wt
        Relaxation -> if(dist[u] + wt < dist[v]){
                            dist[v] = dist[u] + wt
                      }
ALGORITHM
1. List down all the edges of graph(in any order)
2. Create a distance array and initialize all to INT_MAX
3. Initialise dist[src] = 0
4. Relax all these edges for N-1 times
5. Check if there is a negative weight cycle by relaxing one more time, if distance of any node changes it means there is a
   negative weight cycle

DRAWBACK -> Doesnot work for negative weighted cycle
            Since this algotithm doesnt work for -ve weighted cycle, so this wont work for undirected grph with -ve weights
            coz for an edge u-v in undirected graph it is same as u->v and u<-v. So if there is negative weight this becomes -ve weighted cycle
*/
#include <iostream>
#include <queue>
#include <stack>
#define INF 1e9
using namespace std;
  
class edge{
public:
    int u, v, wt;
    edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

void shortestPath(vector<edge> graph, int V, int src){
	// Create a vector for distances and initialize all distances as infinite (INF)
	vector<int> dist(V, INF);

    //Relaxing all the edges V-1 times
    for(int i = 0; i < V-1; i++){
        for(edge e : graph){
            if(dist[e.u] + e.wt < dist[e.v]){
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }
	
    //Relaxing one mmore time to find if negative cycle is present
    bool flag = false;
    for(edge e : graph){
        if(dist[e.u] + e.wt < dist[e.v]){
            flag = true;
            cout << "Has negative weighted cycle" << endl;
            return;
        }
    }
	// Print shortest distances stored in dist[]
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

	

/*
       -1      2
   (0)---->(1)--->(4)
    |   /   |^   /
   4| 3/   2||1 /-3
    | /     || /
    vv<-----v|v
    (2)  5  (3)
*/

int main() {
  	int V;
  	vector<edge> edges; //Represents the graph

    edges.push_back(edge(0, 1, -1));
    edges.push_back(edge(0, 2, 4));
    edges.push_back(edge(1, 2, 3));
    edges.push_back(edge(1, 3, 2));
    edges.push_back(edge(1, 4, 2));
    edges.push_back(edge(3, 1, 1));
    edges.push_back(edge(3, 2, 5));
    edges.push_back(edge(4, 3, -3));

    V = 5;
    shortestPath(edges, V, 0);
	return 0;
}