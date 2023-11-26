// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

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
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &vec : roads){
            int from = vec[0];
            int to = vec[1];
            int  wt = vec[2];
            graph[from].push_back({to, wt});
            graph[to].push_back({from, wt});
        }   
        int src = 0, dst = n-1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        vector<long long> dist(n, 1e15);
        dist[src] = 0;
        vector<int> visitedCnt(n, 0);
        visitedCnt[src] = 1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            long long costTillNow = pq.top().first;
            pq.pop();

            for(auto &p : graph[node]){
                int adj = p.first;
                long long cost = p.second;
                long long pathCost = costTillNow + cost;

                if(pathCost == dist[adj])
                    visitedCnt[adj] = (visitedCnt[adj] + visitedCnt[node]) %((int)1e9+7);
                else if(pathCost < dist[adj]){
                    visitedCnt[adj] = visitedCnt[node];
                    dist[adj] = pathCost;
                    pq.push({dist[adj], adj});
                }
            }
        }
        return visitedCnt[dst]%((int)1e9+7);
    }
};


int main(){
    int n;
    cin >> n;

    int e;
    cin >> e;

    vector<vector<int>> roads(e);
    for(int i = 0; i < e; i++){
        int f, t, wt;
        cin >> f >> t >> wt;
        roads[i] = {f, t, wt};
    }

    Solution s;
    cout << s.countPaths(n, roads);
    return 0;
}