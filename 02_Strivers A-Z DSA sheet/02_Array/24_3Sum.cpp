// https://leetcode.com/problems/3sum/description/
// https://www.youtube.com/watch?v=DhFh8Kw7ymk

// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr) { //Bruteforce
    set<vector<int>> s; //Used to generate unique triplets

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

vector<vector<int>> triplet2(int n, vector<int> &arr) { //Better approach T=O(n^2) S=O(n)+O(size of ans set)
    set<vector<int>> s;
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        unordered_set<int> hashSet;
        for(int j = i+1; j < n; j++){
            int k = -(arr[i]+arr[j]);

            if(hashSet.find(k) != hashSet.end()){
                vector<int> temp = {arr[i], arr[j], k};
                sort(temp.begin(), temp.end());
                s.insert(temp);

            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());

    return ans;
}


//This is just extension of 2 sum approach
vector<vector<int>> triplet3(int n, vector<int> &arr){ //Best approach T=O(n^2) S=O(1)
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        if(i != 0 && arr[i] == arr[i-1]) continue;

        int j = i+1;
        int k = n-1;
        while(j <= k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0)
                j++;
            else if(sum > 0)
                k--;
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }

        }
    }
    return ans;
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
