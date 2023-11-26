
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

void mergeSorted(vector<int> &arr, int l, int m, int h){
    vector<int> left, right;
    for(int i = l; i <= m; i++)
        left.push_back(arr[i]);

    for(int i = m+1; i <= h; i++)
        right.push_back(arr[i]);

    int i1 = 0, i2 = 0;
    int n1 = left.size(), n2 = right.size();
    int idx = l;

    while(i1 < n1 && i2 < n2){
        if(left[i1] < right[i2])
            arr[idx++] = left[i1++];
        else
            arr[idx++] = right[i2++];
    }

    while(i1 < n1) arr[idx++] = left[i1++];
    while(i2 < n2) arr[idx++] = right[i2++];
}

void mergeSort(vector<int> &arr, int l, int h){
    if(l < h){
        int mid = l + (h-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, h);
        mergeSorted(arr, l, mid, h);
    }
}

int main(){
     int n; 
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    mergeSort(vec, 0, n-1);

    for(int num : vec) cout << num << " ";
    return 0;
}