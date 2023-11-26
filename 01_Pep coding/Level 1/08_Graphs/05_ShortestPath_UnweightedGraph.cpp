//In unweighted graph, weight of each node is considered to be 1
// https://www.youtube.com/watch?v=hwCWi7-bRfI

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
        void shortestDist(int, int);
        void shortestPath(int, int);
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

void Graph :: shortestDist(int src, int dest){
    int *dist = new int[v];     //Distance array
    //Marking all distance to infinity
    for(int i = 0; i < v; i++)  
        dist[i] = INT_MAX;
        
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //Iterating over adj nodes of 'node'
        for(auto i : adj[node]){
            if(dist[node] + 1 < dist[i]){    
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    cout << "Minimum distance of " << dest << " from " << src << " is " << dist[dest] << endl;
}

void Graph :: shortestPath(int src, int dest){
    //pair <dist, path>
    pair<int, string> *dist = new pair<int, string>[v];    
    //Marking all distance to infinity
    for(int i = 0; i < v; i++) {
        dist[i].first = INT_MAX;
        dist[i].second = to_string(i) + " ";
    }
    queue<int> q;
    q.push(src);
    dist[src].first = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        //Iterating over adj nodes of 'node'
        for(auto i : adj[node]){
            if(dist[node].first + 1 < dist[i].first){    
                dist[i].first = dist[node].first + 1;
                dist[i].second = dist[node].second + to_string(i) + " ";
                q.push(i);
            }
        }
    }
    cout << "Minimum distance of " << dest << " from " << src << " is " << dist[dest].first << endl;
    cout << "Path : " << dist[dest].second << endl;
}
/*
	    0---- 1
          \   |
           \  |
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
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    g.shortestPath(0, 4);
    return 0;
}