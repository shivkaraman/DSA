// There are n cities and there are roads in between some of the cities. Somehow all the roads are damaged simultaneously. We have to repair the roads to connect the cities again. There is a fixed cost to repair a particular road. Find out the minimum cost to connect all the cities by repairing roads. 
//This is direct application of kruskals algorithm

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

class Edge{
public:
    int u;
    int v;
    int wt;
    Edge(int u, int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class commpare{
public:
    bool operator()(Edge e1, Edge e2){
        return e1.wt < e2.wt;
    }
};

class disjointSet{
private:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;
public:
    disjointSet(int n){
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i]= i;
        }
    }
    int findUparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionByRank(int node1, int node2){
        int p1 = findUparent(node1);
        int p2 = findUparent(node2);

        if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }
        else if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else{
            parent[p1] = p2;
            rank[p2]++;
        }
    }
};

int minSpanningTree(int v, vector<Edge> edges){
    sort(edges.begin(), edges.end(), commpare());
    disjointSet d(v);
    int minCost = 0;

    for(Edge &e : edges){
        if(d.findUparent(e.u) != d.findUparent(e.v)){
            d.unionByRank(e.u, e.v);
            minCost += e.wt;
        }
    }
    return minCost;
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<Edge> graph;
    for(int i = 0; i < E; ++i){
        int v1; cin >> v1;
        int v2; cin >> v2;
        int wt; cin >> wt;
        Edge e(v1, v2, wt);
        graph.push_back(e);
    }
    cout << minSpanningTree(V, graph);
    return 0;
}