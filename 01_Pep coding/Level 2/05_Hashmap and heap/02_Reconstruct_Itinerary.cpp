// https://leetcode.com/problems/reconstruct-itinerary/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;


unordered_map<string, multiset<string>> graph;
vector<string> ans;
void dfs(string vtex){
    multiset<string> &edges = graph[vtex];
    while (!edges.empty()){
        string to = *edges.begin();
        edges.erase(edges.begin());
        dfs(to);
    }
    ans.push_back(vtex);
}  

vector<string> findItinerary(vector<vector<string>> tickets) {
    for (vector<string> &e : tickets) graph[e[0]].insert(e[1]);
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