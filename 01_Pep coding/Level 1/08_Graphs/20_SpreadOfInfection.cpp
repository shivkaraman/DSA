/*
Given a graph representing people and their connectivity. You are given a source person(who gets infected) and time t
You are required to find the no of people infected in time t if inflation sprads to neighbours of infected person in 1 unit of time 
*/
/*
A graph is said to be bipartite if its vertices can be devided into two mutually exclusive and exhaistive sets such tha all 
he edges are present accross the sets
All non cyclic graphs --> Bipartite
If cyclic-> Even Nodes -> Bipartite
            Odd nodes  -> Not Bipartite
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
        void countInfected(int src, int t){
            //pair< node, time >
            queue <pair<int, int>> q;
            vector<int> visited(v, 0);
            q.push({src, 1});
            int count = 0;
            while(!q.empty()){
                pair<int, int> node = q.front();
                q.pop();
                //if already visited, continue
                if(visited[node.first] > 0) continue;
            
                if(node.second > t) break;
                
                count++;
                visited[node.first] = node.second;
                for(int x : adj[node.first]){
                    if(visited[x] == 0){
                        q.push({x, node.second + 1});
                    }
                }
            }   
            cout << count << endl;
        }
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


/*     1      1
    0------3-------4
    |      |       | \
   1|     1|      1|  \1
    |      |       |   \
    1------2       5----6
       1             1   
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

    int t, s;
    cin >> t >> s;
       g.countInfected(s, t);
    return 0;
} 