// https://www.youtube.com/watch?v=Z0hwjftStI4

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

int isPossible(vector<int> arr, int n, int maxPages){
    long long pages = 0;
    int noOfStu = 1;
    for(int i = 0; i < n; i++){
        if(pages + arr[i] <= maxPages)
            pages += arr[i];
        else{
            pages = arr[i];
            noOfStu++;
        }
    }
    return noOfStu;
}


int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high){
        int mid = (low+high)/2;
        int noOfStu = isPossible(arr, n, mid);

        if(noOfStu > m)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}

int main(){
    vector<int> arr = {12,34,67,90};
    cout << findPages(arr, 4, 2);
    return 0;
}