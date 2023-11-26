// IDFS and BFS Implementation for Undirected Graph for Adjacency List

#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph{
        int v;
        list<int> *adj;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest);
        void BFS(int startVertex);
};

// Create a graph with given vertices, and maintain an adjacency list
Graph::Graph(int vertices){
    v = vertices;
    adj = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex){
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    list<int> :: iterator it;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            if(visited[*it] != 1){
                visited[*it] = true;
                q.push(*it);	
			}
        }
    }
}
/*
	    0---- 1
        | \   |
        |  \  |
	    3-----2
	     \	 /
	      \	/
	       4
	      / \
	     5   6
*/
int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.BFS(0);

    return 0;
}