//Minium Spanning Tree

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph{
        int v;
        //vertex , weight
        list<pair<int, int>> *adj;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest, int wt);
        bool hasPath(int, int);
};

// Create a graph with given vertices, and maintain an adjacency list
Graph::Graph(int vertices){
    v = vertices;
    adj = new list<pair<int, int>>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest, int wt){
    adj[src].push_back({dest, wt});
    adj[dest].push_back({src, wt});
}

//E - Check if there is a path from src to destination
//F - Neighbour knows to find if there is a path from itself to dest
//E-F - If neighbour has a path then src definately has a path to dest
bool Graph :: hasPath(int src, int dest){
static bool *visited = new bool[v];
    if (src == dest) return true;
    visited[src] = true;
    for(pair<int, int> p : adj[src]){   
        if(visited[p.first] != true){   //We much check this coz for adj node x-y if we make a call to y through x, y will make a 
            //call to x since they are neighbors. Hence there will be an infinite loop/Stack overflow
            if(hasPath(p.first, dest)) return true;
        }
    }
    visited[src] = false;
    return false;
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
    if(g.hasPath(src, dest))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}