/*
say sum till idx i is S1 and S1%k = x
say sum till idx j is S2 and S2%k = x

=> S1 = k*n + x
      S2 = k*m + x

sum of substr (from idx i->j) = S2-S1 = k(m-n) which is a multiple of k => Divisible by K
Therefore if prefixSum % k repeats, then sum pf  substr from prev occurance to curr occurance is divisible by k


https://www.youtube.com/watch?v=GrV3MTR_Uk0&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=29    => WATCH VIDEO VVIP
*/

#include<iostream>
#include<unordered_map>
#include<vector>
 using namespace std;

 int lenOfSubarray(vector<int> &v, int k) {
    //map<remainder, idx>
    unordered_map<int, int> mp;
    mp[0] = -1;
    int prefixSum = 0;
    int maxL = 0;
    for(int i = 0 ; i < v.size(); i++){
        prefixSum += v[i];
        int rem = prefixSum%k;
        if(rem < 0) rem += k;

        if(mp.find(rem) != mp.end()) maxL = max(maxL, i-mp[rem]);
        else mp[rem] = i;
    }
    return maxL;
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
     cout<<lenOfSubarray(arr, K);
 }