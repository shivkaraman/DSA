// https://leetcode.com/problems/redundant-connection-ii/description/
// https://www.youtube.com/watch?v=d0tqBMRZ6UQ&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=37
/*
 The priblem can be rephased as . Given a tree with each node having atmost one parent, someone has added an edge which is creating a cycle ie converting the tree to graph. We have to remove an edge which wil convert it back to tree. It need not necessarily be the edge that is added.
PROBLEM -> 1. Node with 2 parents
           2. Cycle
           3. Node with 2 parents and cycle  -> Ans is the edge which is causing the cycle
eg              1 
                |
                v
                2    ---> Node with 1 parents (1 and 5) ans2 also a cycle -> ANS is 5-2 because removing 1-2 will not remove cycle
              /   ^       CONSLUSION->FOR CASE 3 THE 2ND EDGE (5->2) IS ALWAYS THE ANSWER
             v     \
             3     5
              \   ^
               v /
                4
Approach
1. Check if any node has 2 parents -> By calculating indegree of all nodes (Case 1 is solved)
2. Detect cycle using DSU (while processing edges, ignore the edge that was recorded as ans 1)
                1 
                |
                v
                2    
              /   ^
             v     \
             3     5
              \   ^
               v /
                4
            1. Detecting 2 parents -> We detect that 2 has two parent node while processing 5->2
               So ans1 = 1->2
                  ans2 = 5->2
            2. Cycle detectionn-> when we detect a cycle we have 2 cases
                1. ans = -1 => case 2, So return the current edge
                2. We have detected that one of the node has 2 parents => ans1 != -1 => ACCORDING TO CONSLUSION WE DERIVED ABOVE
                   2ND EDGE IS THE ANSWER ie ans2
*/


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


class DisjointSet {
public:
    vector<int> parent;
    vector<int> ranks;

    DisjointSet(int n){
        parent.resize(n);
        ranks.resize(n, 0);
        for(int i= 0; i < n; i++)
            parent[i] = i;
    }
    int findPar(int a) {
        if (a == parent[a])
            return parent[a];
        return parent[a] = findPar(parent[a]);
    }
    
    void Union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        
        if (ranks[a] >= ranks[b]) {
            parent[b] = a; 
            ranks[a]++;
        }
        else {
            parent[a] = b; 
            ranks[b]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // Detecting a node with 2 parents
        vector<int> indeg(edges.size()+1, -1);
        int ans2 = -1, ans1 = -1; //Two ans coz in case 3, if first we remove an edge (ans1) and check if cycle is present, if cycle is not present => ans1 is the correct redundant edge, but if cycle is still present => we removed the wrong edge => ans2 is the redundant edge
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(indeg[v] != -1){ //Indeg != -1 => There is already 1 parent for this node
                ans1 = i; //Case 1
                ans2 = indeg[v]; 
            }
            else 
                indeg[v] = i; //We are equating it to i coz we are storing the edge number 
        }

        // Cycle detection 
        DisjointSet ds(edges.size()+1);
        for(int i = 0; i < edges.size(); i++){
            if(i == ans1) continue;
            int u = edges[i][0];
            int v = edges[i][1];

            if(ds.findPar(u) == ds.findPar(v)){
                if(ans1 == -1)
                    return edges[i]; //Case 2
                else
                    return edges[ans2];  //Case 3
            }
            ds.Union(u, v);
        }
        return edges[ans1];
    }
};

int main(){
    
    return 0;
}