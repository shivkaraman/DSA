// https://www.codingninjas.com/studio/problems/k-th-element-of-2-sorted-array_1164159?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(m > n)
        return kthElement(arr2, arr1, m, n, k);

    int N = n+m;
    int low = max(0, k-m), high = min(n, k);
    while(low <= high){
        int mid1 = (low+high)/2;
        int mid2 = k-mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1-1 < n) l1 = arr1[mid1-1];
        if(mid2-1 < m) l2 = arr2[mid2-1];
        if(mid1 < n) r1 = arr1[mid1];
        if(mid2 < m) r2 = arr2[mid2];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return -1;
}

int main(){
    vector<int> arr1 = {1,2,3,5,6};
    vector<int> arr2 = {4,7,8,9,100};
    cout << kthElement(arr1, arr2, arr1.size(), arr2.size(), 6);
    return 0;
}