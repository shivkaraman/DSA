// https://www.interviewbit.com/problems/subarray-with-given-xor

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

/*
The approach is simple. In count of subarray with given sum, we check if target-prefixSum is present in map. Similarly here, we check if target^prefixXOR is present in the map
Mathematically, we can see it like this
    
    _____XOR_____       ->prefix XOR
    |           |
    4  2  2  6  4 3
    |__| |______|   
     x      B

    4^2^2^6^4 = XOR
    (4^2) ^ (2^6^4) = XOR
    x ^ B = XOR
        taking ^ target on both sidex

    x ^ B ^ B = XOR ^ B
    x = XOR ^ B
*/
int solve(vector<int> &arr, int B) {
    unordered_map<int, int> mp;
    int XOR = 0, n = arr.size(), count = 0;
    mp[0]++;
    
    for(int i = 0; i < n; i++){
        XOR = XOR ^ arr[i];
        if(mp.find(B^XOR) != mp.end())
            count += mp[B^XOR];
        mp[XOR]++;
    }
    return count;
}

int main(){
    
    return 0;
}