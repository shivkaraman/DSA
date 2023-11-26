// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. You are required to print the longest sequence of consecutive elements in the array (ignoring duplicates).

// Note -> In case there are two sequences of equal length (and they are also the longest), then print the one for which the starting point of which occurs first in the array.

// Constraints
// 1 <= n <= 30
// 0 <= n1, n2, .. n elements <= 15

#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int res = 0;
        for(int n : nums){
            if(s.find(n) == s.end()) continue;
            s.erase(n);
            
            int prev = n-1,next = n+1;
            while(s.find(prev)!=s.end()) s.erase(prev--);
            while(s.find(next)!=s.end()) s.erase(next++);
            res = max(res,next-prev-1);
        }
        return res;
    }

int main(){
    vector<int>arr;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int data;
        cin >> data;
        arr.push_back(data);
    }
    cout << longestConsecutive(arr);
    return 0;
}