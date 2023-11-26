// https://leetcode.com/problems/cheapest-flights-within-k-stops/

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


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(n == 1) return -1;
        vector<vector<pair<int, int>>> graph(n);
        for(auto &vec : flights){
            int from = vec[0];
            int to = vec[1];
            int  wt = vec[2];
            graph[from].push_back({to, wt});
        }   

        queue<pair<int, pair<int, int>>> q; // <k, node, costTillNow>
        q.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().second.first;
            int costTillNow = q.front().second.second;
            int K = q.front().first;
            q.pop();

            if(K > k) continue;
            
            for(auto &p : graph[node]){
                int adj = p.first;
                int wt = p.second;

                //VVIP-> Here we are comparing cost+wt < dist[adj] and not dist[node]+wt < dist[adj]
                if(costTillNow + wt < dist[adj] && K <= k){ 
                    dist[adj] = costTillNow + wt;
                    q.push({K+1, {adj, dist[adj]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
/*
TO understand why we are doing costTillNow+wt, dryrun for 
n = 4
flights = [[0,1,1], [0,2,5], [1,2,1], [2,3,1]]
src = 0
dst = 3
k = 1

do dryrun for dist[node]+wt < dist[adj] and costTillNow+wt < dist[adj] to understend the difference
*/

int main(){
    int n;
    cin >> n;

    int f;
    cin >> f;

    vector<vector<int>> flights(f);
    for(int i = 0; i < f; i++){
        int f, t, wt;
        cin >> f >> t >> wt;
        flights[i] = {f, t, wt};
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    Solution s;
    s.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}