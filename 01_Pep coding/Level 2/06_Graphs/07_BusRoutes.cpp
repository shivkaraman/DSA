// https://leetcode.com/problems/bus-routes/description/
// https://www.youtube.com/watch?v=WhuiqhMXhxM&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=8

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        //map <stop, busses>
        unordered_map <int, vector<int>> mp;
        for(int i = 0; i < routes.size(); i++){
            for(int j = 0; j < routes[i].size(); j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        unordered_set<int> bv;  //To check if bus is already boarded once -> BUS VISITED
        unordered_set<int> bsv; //To check if the bus stop is already visited -> BUS STOP VISITED
        queue <int> q;
        q.push(source);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int stop = q.front();
                q.pop();
                for(int bus : mp[stop]){
                    if(bv.find(bus) != bv.end()) continue; //If bus is already boarded => continue
                    for(int busStop : routes[bus]){
                        if(bsv.find(busStop) != bsv.end()) continue; //If bus stop is already visited => Continue
                        if(busStop == target) return count+1; //Because current bus is not counted
                        bsv.insert(busStop);
                        
                        q.push(busStop);
                        
                    }
                    bv.insert(bus);
                }
            }
            count++;
        }
        return -1;
    }
};

int main(){
    
    return 0;
}