// https://www.youtube.com/watch?v=R_Mfw4ew-Vo

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

bool isDistPossible(vector<int> &arr, int n, int k, int dist){
    int prevCow = arr[0];
    k--;
    for(int i = 1; i < n; i++){
        if(i - prevCow >= dist){
            k--;
            prevCow = i;
            if(k == 0) return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int n, int k){
    sort(arr.begin(), arr.end());

    int low = 1, high = arr[n-1]-arr[0];
    int ans = 1;
    while(low <= high){
        int mid = (low+high)/2;
        bool check = isDistPossible(arr, n, k, mid);

        if(check){
            low = mid+1;
            ans = mid;
        }
        else
            high = mid-1;
    }
    return ans;
}

int main(){
    
    return 0;
}