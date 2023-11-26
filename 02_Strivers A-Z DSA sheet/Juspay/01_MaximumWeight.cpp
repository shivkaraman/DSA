// https://leetcode.com/discuss/interview-question/2063862/juspay-oa-sde-intern-ppo-on-campus-maximum-weight-node

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

int maxWeight(vector<int> &edges){
    int n = edges.size();
    vector<int> weights(n, 0);
    int mx = 0, idx = -1;

    for(int i = 0; i < n; i++){
        int sec = i;
        int dest = edges[i];

        if(dest == -1) continue;
        weights[dest]++;
        if(weights[dest] >= mx){
            mx = weights[dest];
            idx = max(idx, dest);
        }
    }
    return idx;
}

int main(){
    int n;
    cin >> n;

    vector<int> edges(n);
    for(int i = 0; i < n; i++){
        cin >> edges[i];
    }

    cout << maxWeight(edges);
    return 0;
}