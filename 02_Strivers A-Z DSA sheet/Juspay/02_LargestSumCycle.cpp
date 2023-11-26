// https://leetcode.com/discuss/interview-question/2065974/juspay-oa-sde-intern-ppo-on-campus-largest-sum-cycle

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

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsVis, int &mxLen, int &mxSum){
    visited[node] = true;
    dfsVis[node] = true;

    for(int nbr: graph[node]){
        if(!visited[nbr]){
            dfs(nbr, graph, visited, dfsVis, mxLen, mxSum);
        }
        else if(dfsVis[nbr]){
            int sum = 0;
            int temp = nbr;
            int len = 0;
            do{
                sum += temp;
                temp = graph[temp][0];
                len++;
            }while(temp != nbr);

            if(sum > mxSum){
                mxSum = sum;
                mxLen = len;
            }
            break;
        }   
    }
    dfsVis[node] = false;
}

int largestSumCycle(vector<int> &edges, int n){
    vector<vector<int>> graph(n); //Creating graph
    for(int i = 0; i < n; i++){
        if(edges[i] != -1){
            graph[i].push_back(edges[i]);
        }
    }

    vector<bool> visited(n, false);
    vector<bool> dfsVis(n, false);
    int mxLen = -1, mxSum = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(i, graph, visited, dfsVis, mxLen, mxSum);
    }
    cout << mxSum << endl;
    return mxLen;
}

int main(){
    int n;
    cin >> n;

    vector<int> edges(n);
    for(int i = 0 ; i < n; i++){
        cin >> edges[i];
    }
    cout << largestSumCycle(edges, n);
    return 0;
}