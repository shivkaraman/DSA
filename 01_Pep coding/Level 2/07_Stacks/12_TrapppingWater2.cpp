
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

class mypair{
public:
    int h, i, j;
    mypair(int h, int i, int j){
        this->h = h;
        this->i = i;
        this->j = j;
    }
};

class mycomparator{
public:
    bool operator()(mypair &p1, mypair &p2){
        return p1.h > p2.h;
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n, int m){
        return (r < n && r >= 0 && c < m && c >= 0);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        priority_queue<mypair, vector<mypair>, mycomparator> pq;
        // Adding all border elements into min heap
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    visited[i][j] = true;
                    pq.push(mypair(heightMap[i][j], i, j));
                } 
                else{
                    visited[i][j] = false;
                }
            }
        }

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int water = 0;
        while(!pq.empty()){
            mypair p = pq.top();
            pq.pop();
            int H = p.h;

            for(pair<int, int> &d: dir){
                int nr = p.i + d.first;
                int nc = p.j + d.second;

                if(isValid(nr, nc, n, m) && visited[nr][nc] == false){
                    int nbrH = heightMap[nr][nc];

                    if(nbrH < H){
                        water += H-nbrH;
                        pq.push(mypair(H, nr, nc));
                    }
                    else{
                        pq.push(mypair(nbrH, nr, nc));
                    }
                    visited[nr][nc] = true;
                }
            }
        }
        return water;
    }
};
 
int main(){
    
    return 0;
}