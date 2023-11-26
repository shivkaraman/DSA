
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

void BubbleSort(vector<int> &arr, int n){
    if(n == 1) return;

    for(int j = 0; j < n-1; j++){
        if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
    }

    BubbleSort(arr, n-1);
}

void InsertionSort(vector<int> &arr, int i, int n){
    if(n == 0) return;

    int ele = arr[i];
    int j = i-1;
    while(j >= 0 && arr[j] > ele){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = ele;

    InsertionSort(arr, i+1, n-1);
}

int main(){
    int n; 
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    // BubbleSort(vec, n);
    InsertionSort(vec, 1, n-1);

    for(int i : vec) cout << i << " ";
    return 0;
}