// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

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

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //graph
        unordered_map<char, vector<char>> graph(K);
        for(int i = 1; i < N; i++){
            string prev = dict[i-1];
            string curr = dict[i];
            int idx = 0;
            while(idx < prev.size() && idx < curr.size() && prev[idx] == curr[idx]) idx++;
            
            graph[prev[idx]].push_back(curr[idx]);
        }
        
        for(int i = 'a'; i < 'a'+4; i++){
            if(graph.find(i) == graph.end())
                graph.insert({i, vector<char>{}});
        }

        //Topological sort
        unordered_map<char, int> indeg;
        for(auto &p : graph){
            if(indeg.find(p.first) == indeg.end()) indeg[p.first] = 0;
            for(char &ch : p.second)
                indeg[ch]++;
        }
        
        
        queue<char> q;
        for(auto &p : indeg){
            if(p.second == 0){
                q.push(p.first);
            }
        }
        
        string ans;
        while(!q.empty()){
            char node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto &adj: graph[node]){
                indeg[adj]--;
                if(indeg[adj] == 0)
                    q.push(adj);
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}