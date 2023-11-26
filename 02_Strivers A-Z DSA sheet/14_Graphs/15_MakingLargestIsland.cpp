// https://leetcode.com/problems/making-a-large-island/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }
    void UnionBySize(int u, int v){ 
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;

        if(size[u] <= size[v]){
            parent[u] = v;
            size[v] += size[u]; 
        }
        else if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        bool noZeros = true;
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){ 
                    noZeros = false;
                    continue;
                }
                int cell = n*i+j;
                for(auto &p : dir){
                    int ni = i+p.first, nj = j+p.second;
                    if(ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 0) continue;
                    int ncell = n * ni + nj;
                    ds.UnionBySize(cell, ncell);
                }

            }
        }
        if(noZeros) return n*n;

        int mx = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) continue;
                int curr = 0;
                unordered_set<int> prevPars;
                for(auto &p : dir){
                    int ni = i+p.first, nj = j+p.second;
                    if(ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 0) continue;

                    int ncell = n * ni + nj;
                    int par = ds.findPar(ncell);
                    if(prevPars.find(par) != prevPars.end()) continue;
                    prevPars.insert(par);
                    curr += ds.size[par];
                }
                mx = max(mx, curr+1);
            }
        }
        return mx;
    }
};

int main(){
    
    return 0;
}