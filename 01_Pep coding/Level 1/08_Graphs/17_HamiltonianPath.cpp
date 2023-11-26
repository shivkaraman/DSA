// 1. You are given a graph and a src vertex.
// 2. You are required to find and print all hamiltonian paths and cycles starting from src. The cycles must end with "*" and 
//    paths with a "."

// Note -> A hamiltonian path is such which visits all vertices without visiting any twice. A hamiltonian path becomes a cycle 
//         if there is an edge between first and last vertex.
// Note -> Print in lexicographically increasing order.

//Minium Spanning Tree

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph{
        int v;
        list<int> *adj;
    public : 
        Graph(int v){
            this->v = v;
            adj = new list<int>[v];
        }
        void addEdge(int s, int d){
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        void hamiltonmian(vector<bool> visited, int src, string psf){
            visited[src] = true;
            //Base case
            bool allVisited = true;
            for(bool x : visited){
                if(x == false){
                    allVisited = false;
                    break;
                }
            }
            if(allVisited){
                cout << psf + to_string(src) ;
                for(int node : adj[src]){
                    if(node == psf[0] - '0'){
                        cout << "*" << endl;
                        return;
                    }
                }
                cout << "." << endl;
                return;
            }
            //Code
            for(int node : adj[src]){
                if(visited[node] == false)
                    hamiltonmian(visited, node, psf + to_string(src));
            }
            visited[src] = false;
        }   
};
/*
	    0_______3_______4
        |       |       |\
        |       |       | \
        |_______|_______|__\
        1       2       5   6
*/
int main(){
    int v, e;
	cin >> v >> e;

	Graph g(v);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int src;
    cin >> src;

    vector<bool> visited(v, false);
    g.hamiltonmian(visited, src, "");
    return 0;
}
