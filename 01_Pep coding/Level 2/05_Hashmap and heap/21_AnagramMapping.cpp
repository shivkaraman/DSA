// https://nados.io/question/find-anagram-mappings

#include<bits/stdc++.h>
using namespace std;

vector<int> findMapping(int a1[],int a2[],int n){
    vector<int> ans;
    unordered_map<int, list<int>> mp;
    for(int i = 0; i < n; i++){
        mp[a2[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        ans.push_back(mp[a1[i]].front());
        mp[a1[i]].pop_front();
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int a1[n],a2[n];
    for(int i=0;i<n;i++){
        cin >> a1[i];
    }
    for(int i=0;i<n;i++){
        cin >> a2[i];
    }
    
    vector<int> ans = findMapping(a1,a2,n);
    for(auto a:ans){
        cout << a << " ";
    }
}