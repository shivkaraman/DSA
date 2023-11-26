// Given an m*n matrix mat, Originally, the 2D matrix is all 0 which means there is only sea in the matrix. 
// The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid mat[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size K.

// This question consists of adding edges/nodes dynamically and we need to count the no of components which is 1 => DISJOINT SET


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

class DisjointSet{
public:
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n, int m){
        parent.resize(n * m);
        rank.resize(n * m, 0);
        for(int i = 0; i < n*m; i++) parent[i] = i;
    }
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void Union(int n1, int n2){
        int p1 = findUparent(n1);
        int p2 = findUparent(n2);
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }
        else{
            rank[p1]++;
            parent[p2] = p1;
        }
    }
};

void noOfIslands(int n, int m, vector<pair<int, int>> &ops, vector<vector<bool>> &graph){
    DisjointSet s(n, m);
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int ans = 0;
    for(auto &op : ops){
        int r = op.first;
        int c = op.second;
        int cellno = r * m + c;

        graph[r][c] = 1;
        ans++;

        for(auto &p : dir){
            int nr = r + p.first;
            int nc = c + p.second;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && graph[nr][nc] == 1){
                int adjCell = nr * m + nc;
                if(s.findUparent(cellno) != s.findUparent(adjCell)){
                    s.Union(cellno, adjCell);
                    ans--;
                }
            }
        }
        cout << ans << " ";
    }
}

int main(){
    int m, n, x;
    cin >> n >> m >> x;
    
    vector<vector<bool>> graph(n, vector<bool>(m, false));
    vector<pair<int, int>> ops;
    for(int i = 0; i < x; i++){
        int r, c;
        cin >> r >> c;
        ops.push_back({r, c});
    }
    noOfIslands(n, m, ops, graph);
    return 0;
}