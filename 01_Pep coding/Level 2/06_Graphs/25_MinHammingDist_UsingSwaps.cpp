/*
https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/

Say if swap array=[[0,4],[4,2],[1,4]] 
This impllies we can swap elements of array the following way

    0-4 and 4-2 => 0-4-2
    1-4

Therefore any index can be swapped among 0-1-2-4
We use Disjoint sets to group the swappable indices as above
             0 
           / | \
          1  2  4 

Then we iterate throught the target array and for each target[i], we check if source element with value of target[i] is present in any of the swappable index ie in DS. If we didnt find the element => Increase hamming distance

Say if src = [5,1,2,4,3] target = [1,5,4,2,3] swap array=[[0,4],[4,2],[1,4]] 
       idx    0 1 2 3 4            0 1 2 3 4 
So the subs array will look like this 
    0 ->  5 1 2 3 
    3 ->  4
*/

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

class DisjointSet {
public:
    vector<int> parent;
    vector<int> ranks;

    DisjointSet(int n){
        parent.resize(n);
        ranks.resize(n, 0);
        for(int i= 0; i < n; i++)
            parent[i] = i;
    }
    int findPar(int a) {
        if (a == parent[a])
            return parent[a];
        return parent[a] = findPar(parent[a]);
    }
    
    void Union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        
        if (ranks[a] >= ranks[b]) {
            parent[b] = a; 
            ranks[a]++;
        }
        else {
            parent[a] = b; 
            ranks[b]++;
        }
    }
};

class Solution{
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DisjointSet ds(n);
        
        //Creating group of swappable indices
        for (auto &v : allowedSwaps)
            ds.Union(v[0], v[1]);

        //subs[i] = all elements of source which are swappable between themselves
        vector<unordered_multiset<int>> subs(n);
        for (int i = 0; i < n; i++) {
            int root = ds.findPar(i); //The head of the swappable index group -> 0 in this case
            subs[root].insert(source[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int root = ds.parent[i];
            if (!subs[root].count(target[i]))
                ans++;
            else
                subs[root].erase(subs[root].find(target[i]));
        }
        return ans;
    }
};

int main(){
    
    return 0;
}