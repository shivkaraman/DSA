// Given an array of n distinct elements, find the minimum number of swaps required to sort the array.
// https://www.youtube.com/watch?v=m-8_yQao-lI&list=PL-Jc9J83PIiEuHrjpZ9m94Nag4fwAvtPQ&index=10


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

/*
Approach- 
    1. make a hashmap of <ele, idx>
    2. sort the array
    3. Compare the indices of sorted and unsorted array
       1. If indices are same, that means element was already present in correct position
       2. Else it was swapped-> do the following
        
<ele,idx>    (6,0) (4,1) (2,2) (14,3) (8,4) (10,5) (12,6) (16,7)
sorted       (2,2) (4,1) (6,0) (8,4) (10,5) (12,6) (14,3) (16,7)
        ___________       _____  _____ ______
       |           |     |     ||     ||     |
       |           v     |     v|     v|     v
    (2,2) (4,1) (6,0) (8,4) (10,5) (12,6) (14,3) (16,7)
     0 ^   1     2 |   3 ^    4      5      6 |    7
       |___________|     |____________________|
    
Here each edge is representing SWAPPING
For a cycle of size N there is N-1 swapping ie we neednot count the back edge(the one creating the cycle)
*/
int minSwaps(vector<int> &arr){
    // pair< element, original index>
    vector<pair<int, int>> sorted;
    for(int i = 0; i < arr.size(); i++){
        sorted.push_back({arr[i], i});
    }
    sort(sorted.begin(), sorted.end());

    vector<bool> visited(arr.size());
    int ans = 0;
    for(int i = 0; i < arr.size(); i++){
        if(visited[i] == true || sorted[i].second == i) continue;

        int clen = 0; //Cycle length
        int j = i;
        while(visited[j] != true){
            visited[j] = true;
            j = sorted[j].second;
            clen++;
        }
        ans += clen-1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }
    
    cout<<minSwaps(arr);
}