// You are given a list of strings from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.
// Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

// https://www.youtube.com/watch?v=_u1Mn4_2hIo&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=13

//We just arrange the characters in formof graph based on the given priority and sort topologically

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;

void khansAlgo(unordered_map<char, unordered_set<char>> &graph, vector<string> &words){
    //Initiating indegree of each char to 0
    unordered_map<char, int> indeg;
    for(string s : words){
        for(char ch : s){
            indeg[ch] = 0;
        }
    }
    //Calculating indegree of each vertes
    for(auto s : graph){
        for(auto x : s.second){
            indeg[x]++;
        }
    }

    queue<char> q;
    //Pushing all nodes with indegree 0 to queue
    for(pair<char, int> p : indeg){
        if(p.second == 0) q.push(p.first);
    }

    int idx = 0;
    vector<char> ans(indeg.size());
    while(!q.empty()){
        char node = q.front();
        q.pop();

        ans[idx++] = node;
        for(char adj : graph[node]){
            indeg[adj]--;

            if(indeg[adj] == 0) q.push(adj);
        }
    }
    if (idx == indeg.size()){
        for(char ch : ans) cout << ch;
    }
    else cout << -1;
}

int main(){
    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];

    //Making graph of chars based on their priority <char, set of all chars which are greater than it>
    unordered_map<char, unordered_set<char>> graph;
    for(int i = 0; i < n-1; i++){
        string curr = words[i];
        string next = words[i+1];
        int len = min(curr.size() ,next.size());

        for(int j = 0; j < len; j++){
            char c1 = curr[j];
            char c2 = next[j];
            if(c1 != c2){
                if(graph[c1].find(c2) == graph[c1].end()){
                    graph[c1].insert(c2);
                }
                break;
            }
        }
    }
    khansAlgo(graph, words);
    return 0;
}