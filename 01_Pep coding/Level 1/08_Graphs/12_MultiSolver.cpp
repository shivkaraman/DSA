// find and print the values of 
// 1 Smallest path and it's weight separated by an "@"
// 2 Largest path and it's weight separated by an "@"
// 3 Just Larger path (than criteria in terms of weight) and it's weight separated by an "@"
// 4 Just smaller path (than criteria in terms of weight) and it's weight separated by an "@"
// 5 Kth largest path and it's weight separated by an "@"

//Minium Spanning Tree

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class myComparator{
    public :    
        bool operator()(const pair<int, string> &p1,const  pair<int, string> &p2){
            return p1.first > p2.first;
        }
};

class Graph{
        int v;
        //vertex , weight
        list<pair<int, int>> *adj;
    public:
        Graph(int vertices);
        void addEdge(int src, int dest, int wt);
        void pathsMultisolver(int, int, vector<bool>, string psf, int wsf, int WT, int k);
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

string spath;
int spathwt = INT_MAX;

string lpath;
int lpathwt = INT_MIN;

string cpath;
int cpathwt = INT_MAX;

string fpath;
int fpathwt = INT_MIN;
priority_queue<pair<int, string>, vector<pair<int, string>>, myComparator> pq;

void Graph :: pathsMultisolver(int src, int dest, vector<bool> visited, string psf, int wsf, int WT, int k){
    if(src == dest){
        if(wsf > lpathwt){
            lpath = psf;
            lpathwt = wsf;
        }
        if(wsf < spathwt){
            spath = psf;
            spathwt = wsf;
        }
        if(wsf > WT && wsf < cpathwt){
            cpathwt = wsf;
            cpath = psf;
        }
        if(wsf < WT && wsf > fpathwt){
            fpathwt = wsf;
            fpath = psf;
        }
        if(pq.size() < k)
            pq.push({wsf, psf});
        else if(wsf > pq.top().first){
            pq.pop();
            pq.push({wsf, psf});
        }
        return;
    }
    visited[src] = true;
    for(pair<int, int> &p : adj[src]){
        if(visited[p.first] == false){
            pathsMultisolver(p.first, dest, visited, psf + to_string(p.first), wsf + p.second, WT, k);
        }
    }
    visited[src] = false;
}

/*     40      2
    0------3-------4
    |      |       | \
  10|    10|      3|  \8
    |      |       |   \
    1------2       5----6
       10            3
*/
int main(){
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i = 0; i < E; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        g.addEdge(x, y, wt);
    }
    int src, dest;
    cin >> src >> dest;

    int WT, k;
    cin >> WT >> k;
    vector<bool> visited(V, 0);

    g.pathsMultisolver(src, dest, visited, to_string(src), 0, WT, k);

    cout << "Smallest Path : " << spath << "@" << spathwt << endl;
    cout << "Largest Path : " << lpath << "@" << lpathwt << endl;
    cout << "Just Larger Path than " << WT << " : " << cpath << "@" << cpathwt << endl;
    cout << "Just Smaller Path than " << WT << " : " << fpath << "@" << fpathwt << endl;
  cout << k << "th largest path : " << pq.top().second << "@" << pq.top().first << endl;
    return 0;
}