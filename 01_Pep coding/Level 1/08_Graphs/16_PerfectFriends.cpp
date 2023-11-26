// 1. You are given a number n (representing the number of students). Each student will have an id 
//      from 0 to n - 1.
// 2. You are given a number k (representing the number of clubs)
// 3. In the next k lines, two numbers are given separated by a space. The numbers are ids of 
//      students belonging to same club.
// 4. You have to find in how many ways can we select a pair of students such that both students are 
//      from different clubs.

//Get connected components application
//n -> No of students-> vertices
//k-> no of edges

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

int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;

    Graph g(n);
    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<vector<int>> comps;    //To store all connected components
    vector<bool> visited(n, false); 
    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            vector<int> comp;     //To store one single component
            g.getConnectedComponent(i, visited, comp);
            comps.push_back(comp);
        }
    }

    int count = 0;
    for(int i = 0; i < comps.size(); i++){
        for(int j = i+1; j < comps.size(); j++){
            count += comps[i].size() * comps[j].size();
        }
    }
    cout << count << endl;
    return 0;
}