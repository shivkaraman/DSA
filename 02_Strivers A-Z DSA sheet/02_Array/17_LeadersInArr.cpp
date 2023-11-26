//Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

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

vector<int> superiorElements(vector<int>&arr) {
    vector<int> ans;
    int n = arr.size();
    int mx = arr[n-1];
    ans.push_back(arr[n-1]);
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > mx)
            ans.push_back(arr[i]);
        mx = max(mx, arr[i]);
    }
    return ans;
}

int main(){
    
    return 0;
}