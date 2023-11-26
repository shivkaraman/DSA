// https://leetcode.com/problems/regions-cut-by-slashes/
// https://www.youtube.com/watch?v=Wafu5vOxPRE&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=29

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
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);  //Rank of all elements is initially zero
        parent.resize(n);
        for (int i = 0; i < n; i++) { 
            parent[i] = i;  //Initially, element is parent of itself => Size of each component is 1
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        
        return parent[node] = findUPar(parent[node]);
    }

    void Union(int p1, int p2) {
        if (p1 == p2) return;
        //Whoever has a smaller rank is connected to bigger rank => Bigger rank is the parent after union
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        }
        else if (rank[p2] < rank[p1]) {
            parent[p2] = p1;
        }
        //If rank is same, make anyone as parent, but here we increase the rank of the parent by 1
        else {
            parent[p2] = p1;
            rank[p1]++;
        }
    }
};

//In this question we treat the whole box as a collection of ppoints and the sashes as a connection between points. A new region is created in the graph whenever a new cycle is created
int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    int N = n+1;

    //connecting all points on the boundary of box
    DisjointSet ds(N * N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == 0 || i == N-1 || j == 0 || j == N-1){
                int cellno = i*N + j;
                if(cellno != 0) ds.Union(0, cellno);
            }
        }
    }

    int ans = 1;
    //A forward slash at idx (i,j) connects points (i, j+1) and (i+1,j)
    //A backward slash at idx (i,j) connects points (i, j) and (i+1,j+1)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '/'){
                int cell1 = i*N + (j+1);
                int cell2 = (i+1)*N + j;    

                int p1 = ds.findUPar(cell1);
                int p2 = ds.findUPar(cell2);

                if(p1 == p2) ans++;
                else ds.Union(p1, p2);

            }
            else if(grid[i][j] == '\\'){
                int cell1 = i*N + j;
                int cell2 = (i+1)*N + (j+1);

                int p1 = ds.findUPar(cell1);
                int p2 = ds.findUPar(cell2);

                if(p1 == p2) ans++;
                else ds.Union(p1, p2);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    cout << regionsBySlashes(grid);
    return 0;
}