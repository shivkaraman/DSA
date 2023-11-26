// Pepcoding offers total of n courses labelled from 0 to n-1.
// Some courses may have prerequisites. you have been given m pairs ai,bi. where 1 pair means you must take the course bi before the course ai.
// Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses. If it is impossible to finish all courses print -1.

//This is nothing bt topological sorting -> USE DFS or KHANS ALGO


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

vector<int> khansAlgo(vector<vector<int>> graph){
    //Calculating indegree of each vertes
    vector<int> indeg(graph.size());
    for(int i = 0; i < graph.size(); i++){
        for(int x : graph[i]){
            indeg[x]++;
        }
    }

    queue<int> q;
    //Pushing all nodes with indegree 0 to queue
    for(int i = 0; i < graph.size(); i++){
        if(indeg[i] == 0) q.push(i);
    }

    int idx = 0;
    vector<int> ans(graph.size());
    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans[idx++] = node;
        for(int adj : graph[node]){
            indeg[adj]--;

            if(indeg[adj] == 0) q.push(adj);
        }
    }
    return idx == graph.size() ? ans : vector<int> {-1};
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> ans = khansAlgo(graph);
    for(int node : ans) cout << node << " ";
    return 0;
}