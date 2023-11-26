//Topologiocal sort--> It is a permutation of all vertices for a directed graph in called a topological sort if for all directed
//  edges uv, u appears before v in the graph.

#include <iostream>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class Graph{ 
        int v;
        list<int> *adj;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest);
        void topologicalSort(int, vector<bool> &, stack<int>&);
};
// Create a graph with given vertices, and maintain an adjacency list
Graph::Graph(int vertices){
    v = vertices;
    adj = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest){
    adj[src].push_back(dest);
}

void Graph :: topologicalSort(int src, vector<bool> &visited, stack<int> &s){
    visited[src] = true;
    for(int node : adj[src]){
        if(visited[node] == false)
            topologicalSort(node, visited, s);
    }
    s.push(src);
}
/*     
    0----->3<------4
    |      ^       | \
    |      |       |  \
    v      |       v   v
    1----->2       5<---6

*/
int main(){
    int v, e;
    cin >> v >> e;
    Graph g(v);
    for(int i = 0; i < e; i++){  
        int u , v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    vector<bool> visited(v, false);
    stack<int> s;
    for(int i = 0; i < v; i++){
        if(visited[i] == false){
            g.topologicalSort(i, visited, s);
        }
    }
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
} 
