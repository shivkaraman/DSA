//Adjascency list implementation

#include <iostream>
#include <list>
using namespace std;

class Graph{
        int v;
        list<int> *adj;
        bool *visited;
    public : 
        Graph(int v){
            this->v = v;
            adj = new list<int>[v];
            visited = new bool[v];
            for(int i = 0; i < v; i++)
                visited[i] = 0;
        }
        void addEdge(int s, int d){
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        void DFS(int);
};

void Graph :: DFS(int node){
    visited[node] = 1;
    cout << node << " ";
    list <int> :: iterator it;
    for(it = adj[node].begin(); it != adj[node].end(); it++){
        if(visited[*it] != 1)   
            DFS(*it);
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

    g.DFS(0);

    return 0;
}