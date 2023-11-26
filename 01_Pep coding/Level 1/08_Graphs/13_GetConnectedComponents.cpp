// https://www.youtube.com/watch?v=8UBwFE8H4Mc&list=TLGGKjIiZRUtV84yNTAxMjAyMg&t=842s
// 1. We will apply DFS for every unvisited vertex of the graph.
// 2. While we encounter any vertex that has not already been visited, we will mark it visited and add it to the vector.
// 3. Once we complete the traversal of one component, we will add that component's arraylist to our answer vector of vector.

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
};
/*
	    0       3       4
        |       |       |
        |       |       | 
        |       |       |  
        1       2       5---6
Connected comp -> {[0,1], [2,3], [4,5,6]}

*/
int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    vector<vector<int>> comps;    //To store all connected components
    vector<bool> visited(7, false); 
    for(int i = 0; i < 7; i++){
        if(visited[i] == false){
            vector<int> comp;     //To store one single component
            g.getConnectedComponent(i, visited, comp);
            comps.push_back(comp);
        }
    }

    cout << "{";
    for(int i = 0; i < comps.size(); i++){
        cout << "[";
        for(int j = 0; j <  comps[i].size(); j++){
            cout << comps[i][j] ;
            if(j != comps[i].size()-1)
                cout << ", ";
        }
        cout << "]";
        if(i != comps.size()-1)
                cout << ", ";
    }
    cout << "}";
    return 0;
}