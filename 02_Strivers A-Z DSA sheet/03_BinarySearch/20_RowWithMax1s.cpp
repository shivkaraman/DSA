// https://www.codingninjas.com/studio/problems/row-of-a-matrix-with-maximum-ones_982768?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int lowerBound(vector<int> &arr, int val){
    int low = 0, high = arr.size()-1;
    int ans = arr.size();
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] >= val){
            ans = mid;
            high = mid-1;
        }
        else    
            low = mid+1;
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int mx = 0, index = -1;
    for(int i = 0; i < n; i++){
        int idx = lowerBound(matrix[i], 1);
        int count = m-idx;
        if(count > mx){
            mx = count;
            index = i; 
        }
    }
    return index;
}

int main(){
    vector<vector<int>> vec  = {{0, 0, 1, 1, 1}, 
                                {0, 0, 0, 1, 1}, 
                                {1, 1, 1, 1, 1}, 
                                {0, 0, 0, 0, 0}};

    cout << rowWithMax1s(vec, 4, 5);
    return 0;
}