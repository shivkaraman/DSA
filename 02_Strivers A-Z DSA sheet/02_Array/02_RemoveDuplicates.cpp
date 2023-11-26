//Remove duplicates in a sorted array


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
    int i = 0; 
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[++i] = arr[j];
        }
    }
    return i;
}

int main(){
    int n; 
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    n = solution(arr, n);
    for(int i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}