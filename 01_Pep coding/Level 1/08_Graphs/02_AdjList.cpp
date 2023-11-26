//Adjascency list implementation

#include <iostream>
#include <list>
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
            adj[s].push_front(d);
            adj[d].push_front(s);
        }
        void printGraph(){
            for(int i = 0; i < v; i++){
                cout << "\nVertex " << i << " : ";
                for(int x : adj[i])
                    cout << x << " -> ";
                cout << "NULL" << endl;
            }
        }
};
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

    g.printGraph();
    return 0;
}