// https://www.youtube.com/watch?v=sAk4W8q0Rmw&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=23

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class Pair{
public:
    int par;
    int disc;
    int low;
    bool isAP;
    Pair(){
        par = 0;
        disc = 0;
        low = 0;
        isAP = false;
    }
};

void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited, vector<Pair> &ap, int disc){
    ap[u].disc = ap[u].low = disc;
    int cnt = 0; //Thsi variable is used to keep the count of no of dfs calls we make. This is useful 

    visited[u] = true;
    for(int v : graph[u]){
        //If nbr is parent => nbr already is present in the path from src to current node 
        if(v == ap[u].par) continue;
        //If nbr is not parent but is visited then the edge curr->nbe is not along the path from src to curr node  => low can be updated
        else if(visited[v]){
            ap[u].low = min(ap[u].low, ap[v].disc);
        }
        //else it is an unvisited nod => DFS
        else{
            ap[v].par = u;
            dfs(graph, v, visited, ap, disc+1); 
            cnt++;

            ap[u].low = min(ap[u].low, ap[v].low);
            //Parent[u] = -1 => it is actual source. 
            if(ap[u].par == -1 ){ 
                if(cnt >= 2)
                    ap[u].isAP = true;
            }
            else if(ap[v].low >= ap[u].disc){
                ap[u].isAP = true;
            }
        }
    }
}

void articulationPoint(vector<vector<int>> &graph, int v){
    vector<bool> visited(v, false);
    vector<Pair> ap(v);
    ap[0].par = -1;

    dfs(graph, 0, visited, ap, 1);
    for(int i = 0; i < v; i++){
        if(ap[i].isAP) cout << i+1 << " ";
    }

}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }
    articulationPoint(graph, v);
    return 0;
}