//THis is used to find the minnimum spanning tree
// Spanning tree -> Suub graph of a graph having V vertices (same os original graph) and V-1 edges
// No of spanning trees = e
//                         C - no of cycles
//                          v-1
// C - Combination

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Pair{
    public :
        int v;  //Vertex
        int av; //Acquiring vertex
        int wt;  //Weight
        Pair(int wt, int v, int av){
            this->v = v;
            this->av = av;
            this->wt = wt;
        }
        Pair();
};

class myComparator{
    public :
        bool operator()(const Pair &p1, const Pair &p2){
            return p1.wt > p2.wt;
        }
};

class Graph{
        int v;
        //vertex , weight
        list<pair<int, int>> *adj;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest, int wt);
        void prims(int);
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

void Graph :: prims(int src){
    vector<bool> visited(v, false);

    // pair <weight, vertex, acquring vertex>
    priority_queue <Pair, vector<Pair>, myComparator> pq;
    pq.push(Pair(0, src, -1)); //-1-> Non existing vertex

    cout << "V AV WT" << endl;
    while(!pq.empty()){
        Pair p = pq.top();
        pq.pop();

        //If the node is already visited -> Continue (To avoid cycle)
        if(visited[p.v] == true) continue;

        //If unvisited, mark visited and print
        visited[p.v] = true;
        //Avoiding source node
        if(p.av != -1) cout << p.v << "  " << p.av << "  " << p.wt << endl;

        //Explore all unvisited adj nodes of current node 
        for(pair<int, int> &nbr : adj[p.v]){
            if(visited[nbr.first] == false){
                pq.push(Pair(nbr.second, nbr.first, p.v));
            }
        }
    }
} 

/*     2      5
    1------2-----5
    |      |    /
   1|     4|   /1
    |      |  / 
    4------3 /
       3
*/
int main(){
    Graph g(6);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(3, 5, 1);

    g.prims(1);
    return 0;
}