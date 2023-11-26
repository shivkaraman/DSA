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
            adj[s].push_front(d);
            adj[d].push_front(s);
        }
        void getConnectedComponent(int src, vector<bool> &visited, vector<int> &connectedComp){
            visited[src] = true;
            connectedComp.push_back(src);
            for(int &edge : adj[src]){
                if(visited[edge] == false){
                    getConnectedComponent(edge, visited, connectedComp);
                }
            }
        }
        void display(vector<vector<int>> &comps){
            
        }
};
/*
	    0_______3_______4
        |       |       |\
        |       |       | \
        |_______|       |__\
        1       2       5   6
*/
int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    //If a graph is connected, all nodes must be visited in one traversal
    vector<bool> visited(7, false); 
    vector<int> comp;
    g.getConnectedComponent(0, visited, comp);
    for(bool x : visited){
        if(x == false) cout << "false" << endl;
    }
    cout << "true" << endl;

    return 0;
}