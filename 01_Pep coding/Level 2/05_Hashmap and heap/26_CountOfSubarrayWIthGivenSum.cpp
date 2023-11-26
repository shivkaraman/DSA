//We check if (curr sum - k) occured before, if yes that means the sum of elements after that element is k

#include<iostream>
#include<unordered_map>
#include<vector>
 using namespace std;
 
 // Function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 int countOfSubarray(vector<int> &v, int k) {
    //map<sum, freq>
    unordered_map<int, int> mp;
    int prefixSum = 0;
    int count = 0;
    mp[0] = 1;
    for(int i : v){
        prefixSum += i;
        mp[prefixSum]++;
        if(mp.find(prefixSum-k) != mp.end()) count += mp[prefixSum-k];
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