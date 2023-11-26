
#include<iostream>
#include<unordered_map>
#include<vector>
 using namespace std;

 int countOfSubarray(vector<int> &v, int k) {
    //map<remainder, freq>
    unordered_map<int, int> mp;
    mp[0] = 1;
    int prefixSum = 0;
    int count = 0;
    for(int i = 0 ; i < v.size(); i++){
        prefixSum += v[i];
        int rem = prefixSum%k;
        if(rem < 0) rem += k;

        if(mp.find(rem) != mp.end()) count += mp[rem];
        mp[rem]++;
    }
    return count;
 }
 
 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for (int j = 0; j < n; j++) {
         int val;
         cin>>val;
         arr.push_back(val);
     }
     int K;
     cin>>K;
     cout<<countOfSubarray(arr, K);
 }