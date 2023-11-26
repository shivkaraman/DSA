// https://leetcode.com/problems/number-of-provinces/
// This question is just NO OF CONNECTED COMPONENTS using DSU

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

class disjointSet{
public:
    vector<int> parent;
    vector<int> rank;

    disjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findUparent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void Union(int a, int b){
        int p1 = findUparent(a);
        int p2 = findUparent(b);   

        if(p1 == p2) return;  
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        disjointSet ds(n );

        for(int i = 0; i< n; i++){
            for(int j = 0; j < n; j++){
                if(i == j || isConnected[i][j] == 0) continue;  

                isConnected[j][i] = 0;
                ds.Union(i, j);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(ds.findUparent(i) == i) ans++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}