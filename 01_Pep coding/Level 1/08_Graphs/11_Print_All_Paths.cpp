//Minium Spanning Tree

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph{
        int v;
        //vertex , weight
        list<pair<int, int>> *adj;
        bool *visited;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest, int wt);
        void printAllPaths(int, int, string);
};

// Create a graph with given vertices, and maintain an adjacency list
Graph::Graph(int vertices){
    v = vertices;
    adj = new list<pair<int, int>>[vertices];
    visited = new bool[v];
    for(int i=0; i<v; i++)
        visited[i] = 0;
}

// Add edges to the graph
void Graph::addEdge(int src, int dest, int wt){
    adj[src].push_back({dest, wt});
    adj[dest].push_back({src, wt});
}

//level-option approach
//At each level, we have options of adj nodes
void Graph :: printAllPaths(int src, int dest, string path){
    if(src == dest){
        cout << path + to_string(dest) << endl;
        return;
    }
    visited[src] = true;
    for(pair<int, int> &p : adj[src]){
        if(visited[p.first] == false){
            printAllPaths(p.first, dest, path + to_string(src));
        }
    }
    visited[src] = false;
}

/*     1      1
    0------3-------4
    |      |       | \
   1|     4|      1|  \1
    |      |       |   \
    1------2       5----6
       1             1
*/
int main(){
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        g.addEdge(x, y, wt);
    }
    int src, dest;
    cin >> src >> dest;
    g.printAllPaths(src, dest, "");
    return 0;
}