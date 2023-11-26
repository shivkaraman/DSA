// https://youtu.be/3gbO7FDYNFQ

#include <iostream>
using namespace std;

int rankk[10000];
int parent[10000];

void makeSet(int n){
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

 int findParent(int node){
    if(parent[node] == node) return node;

    return parent[node] = findParent(parent[node]);
 }

void Union(int u, int v){
    u = findParent(u);
    v = findParent(v);

    if(rankk[u] > rankk[v]) parent[v] = u;
    else if(rankk[u] > rankk[v]) parent[u] = v;
    else{
        parent[v] = u;
        rankk[u]++;
    }
}

int main(){
    makeSet(10);

    int m;
    cin >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    //If 2 and 3 belong to same component or not
    if(findParent(2) != findParent(3)){
        cout << "Different Components" << endl;
    }
    else{
        cout << "Same component" << endl;
    }
}