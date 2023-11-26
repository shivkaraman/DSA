
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> nodeToRoot(vector<int> &parent, int target){
    int curr = target;
    vector<int> path;
    do{
        path.push_back(curr);
        curr = parent[curr];
    }while(curr != -1);

    return path;
}

int LCA(vector<int> &parent, int node1, int node2){
    vector<int> path1 = nodeToRoot(parent, node1);
    vector<int> path2 = nodeToRoot(parent, node2);

    int i = path1.size()-1;
    int j = path2.size()-1;
    int lca = -1;
    while(i >= 0 && j >= 0){
        if(path1[i] != path2[j])
            break;
        lca = path1[i];
        i--;
        j--;
    }
    return lca;
}

int main(){
    int n;
    cin >> n;

    vector<int> parent(n);
    for(int i = 0; i < n; i++){
        cin >> parent[i];
    }

    int n1, n2;
    cin >> n1 >> n2;

    cout << LCA(parent, n1, n2);
    return 0;
}