// https://leetcode.com/problems/network-delay-time/

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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        for(auto &vec : times){
            int from = vec[0];
            int to = vec[1];
            int  wt = vec[2];
            graph[from].push_back({to, wt});
        }   

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        
        int ans = -1;
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();

            for(auto &p : graph[node]){
                int adj = p.first;
                int time = p.second;

                if(dist[node]+time < dist[adj]){
                    dist[adj] = dist[node] + time;
                    pq.push({dist[adj], adj});
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(i != k && dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;

    int f;
    cin >> f;

    vector<vector<int>> times(f);
    for(int i = 0; i < f; i++){
        int f, t, wt;
        cin >> f >> t >> wt;
        times[i] = {f, t, wt};
    }

    int k;
    cin >> k;

    Solution s;
    s.networkDelayTime(times, n, k);
    return 0;
}