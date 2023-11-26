

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

int solution(vector<int> &arr, int n){
    int mx = INT_MIN,  smx = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > mx){
            smx = mx;
            mx = arr[i];
        }
    }
    return smx;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << solution(arr, n);
    return 0;
}