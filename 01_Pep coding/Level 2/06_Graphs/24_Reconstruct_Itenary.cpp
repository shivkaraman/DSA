// https://leetcode.com/problems/reconstruct-itinerary/
// https://www.youtube.com/watch?v=U33blOQRaJ0
// This uses the euratian path approach

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

//map <source, priorityQueue<destination>>  -> PQ because we are asked to choose the cities in lexicoraphical order
unordered_map<string, multiset<string>> graph;
vector<string> ans;
void dfs(string vtex){
    multiset<string> &edges = graph[vtex];
    while (!edges.empty()){
        string to = *edges.begin();
        edges.erase(edges.begin()); //Marking the edge as visited. By doing so, we need not check if this edge is visited or not in further interation coz the edge doesnt exist now 
        dfs(to);
    }
    ans.push_back(vtex);
}  

vector<string> findItinerary(vector<vector<string>> tickets) {
    for (vector<string> &e : tickets) 
        graph[e[0]].insert(e[1]);
    dfs("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
} 

void display(vector<string> vec){
    for(string &s : vec) cout << s << " ";
}

int main(){
    int n;
    cin >> n;

    vector<vector<string>> tickets(n, vector<string> (2));
    for(int i = 0; i < n; i++){
        cin >> tickets[i][0] >> tickets[i][1];
    }
    vector<string> ans = findItinerary(tickets);
    display(ans);
    return 0;
}