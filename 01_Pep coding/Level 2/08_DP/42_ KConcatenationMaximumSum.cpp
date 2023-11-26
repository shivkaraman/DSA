// https://leetcode.com/problems/k-concatenation-maximum-sum/

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

int sum(vector<int> &arr){
    int s = 0;
    for(int i : arr) s += i;
    return s;
}

int kadanes(vector<int> &arr){
    int currSum = arr[0];
    int maxSum = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(currSum >= 0)
            currSum += arr[i];
        else 
            currSum = arr[i];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int kConcatenationMaxSum(vector<int> arr, int k) {
    int s = sum(arr);
    if(k == 1)
        return kadanes(arr);
    else{
        arr.insert(arr.end(), arr.begin(), arr.end()); //Creating 2 copies
        if(s >= 0)
            return kadanes(arr) + (k-2)*s;
        else
            return kadanes(arr);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;

    cout << kConcatenationMaxSum(arr, k);
    return 0;
}