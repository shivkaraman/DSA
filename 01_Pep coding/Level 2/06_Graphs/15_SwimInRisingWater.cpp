// https://leetcode.com/problems/swim-in-rising-water/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;
class myPair{
public: 
    int i, j, maxt;
    myPair(int i , int j, int maxt){
        this->i = i;
        this->j = j;
        this->maxt = maxt;
    }
};

class compare{
public:
    bool operator() (myPair x, myPair y){
        return x.maxt > y.maxt;
    }
};

// This is an application of dijkstra algorithm, because at each step we have to choose a minimum between the adjascent nodes
class Solution {
public:
    int ans = 1e9;
     bool isValid(int i, int j, int n){
        return !(i < 0 || j < 0 || i == n || j == n); 
     }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<myPair, vector<myPair>, compare> pq;
        vector<vector<bool>> visited (n, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        pq.push(myPair(0, 0, grid[0][0]));
        visited[0][0] = true;
        while(!pq.empty()){
            myPair node = pq.top();
            pq.pop();

            if(node.i == n-1 && node.j == n-1){
                return node.maxt;
            }
            for(auto p : dir){
                int ni = node.i + p.first;
                int nj = node.j + p.second;

                if(!isValid(ni, nj, n) || visited[ni][nj]) continue;

                pq.push(myPair(ni, nj, max(node.maxt, grid[ni][nj])));
                visited[ni][nj] = true;
            }
        }
        return -1;
    }
};

int main(){
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    Solution s;
    cout << s.swimInWater(grid);
    return 0;
}