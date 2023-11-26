// https://leetcode.com/problems/critical-connections-in-a-network/description/
//Direct application of attriculation point

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
    Pair(){
        par = 0;
        disc = 0;
        low = 0;
    }
};

class Solution {
public:
    
    void dfs(vector<vector<int>> &graph, int u, vector<bool> &visited, vector<Pair> &ap, int disc, vector<vector<int>> &ans){
        visited[u] = true;
        ap[u].disc = disc;
        ap[u].low = disc;
        int cnt = 0;

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
                dfs(graph, v, visited, ap, disc+1, ans);

                ap[u].low = min(ap[u].low, ap[v].low);
                if(ap[u].par == -1){
                    cnt++;
                    if(cnt >= 2){
                        ans.push_back({u, v});
                    } 
                }
                else if(ap[v].low >= ap[u].disc){
                    ans.push_back({u, v});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& graph){
        vector<bool> visited(v, false);
        vector<Pair> ap(v);
        vector<vector<int>> ans; 
        ap[0].par = -1;

        dfs(graph, 0, visited, ap, 1, ans);
        return ans;
    }
};

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    Solution s;
    vector<vector<int>> ans = s.criticalConnections(v, graph);
    for(auto &p: ans){
        cout << p[0] << " " << p[1] << endl;
    }
}