
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

void bubbleSort(vector<int> &arr, int n){
    for(int i  = 0; i < n; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

void selectionSort(vector<int> &arr, int n){
    for(int i = 0; i < n; i++){
        int mn = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[mn])
                mn = j;
        }
        swap(arr[i], arr[mn]);
    }
}

void insertionSort(vector<int> &arr, int n){
    for(int i = 1; i < n; i++){
        int ele = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > ele){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = ele;
    }
}

int main(){
    int n; 
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    // bubbleSort(vec, n);
    // selectionSort(vec, n);
    insertionSort(vec, n);
    for(int i : vec) cout << i << " ";
    return 0;
}