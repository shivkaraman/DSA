/*
A graph is said to be bipartite if its vertices can be devided into two mutually exclusive and exhaistive sets such tha all 
hte edges are present accross the sets
All non cyclic graphs --> Bipartite
If cyclic-> Even no of Nodes -> Bipartite
            Odd  no of nodes -> Not Bipartite
If there are dirferent components in a graph --> Then for graph to be bipartite, all the commponents must be bipartite
*/

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
        bool isBiparitie(int src, vector<int> &visited);
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

bool Graph :: isBiparitie(int src, vector<int> &visited){
    // <node, level at which it is visited>
    queue<pair<int, int>> q;
    q.push({src, 0});
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        //if node is already visited
        if(visited[node.first] != -1){
            //visited-> contains level at which node was visited
            //node.second -> current level
            //If they both dont match => the node is being visited at different levels => Not bipartite
            if(node.second != visited[node.first]){
                return false;
            }
        }
        //If unvisited, mark 'visited at current level'
        visited[node.first] = node.second;
        for(int i : adj[node.first]){
            if(visited[i] == -1){
                q.push({i, node.second + 1});
            }
        }
    }
    return true;
}

/*
        0_______3_______4
        |       |       |\
        |       |       | \
        |_______|_______|__\    
        1       2       5   6   //nOT BIPARTITE

        0_______3_______4
        |       |       |\
        |       |       | \
        |       |       |  \
        1       2       5   6   BIPARTITE
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

    //Not visited-> -1, if visited -> visited[idx] = level at which visited
    vector <int> visited(v, -1);
    //We are checking bipartite inside a loop coz If graph contains different commponenst, then all needs to be checked
    for(int i = 0; i < e; i++){
        if(visited[i] == -1){
            bool check = g.isBiparitie(i, visited);
            if(!check){
                cout << "Not Bipartite" << endl;
                return 0;
            }
        }
    }
    cout << "Bipartite" << endl;
    return 0;
} 