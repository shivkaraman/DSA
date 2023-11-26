
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

int pivot(vector<int> &arr, int l, int h){
    int p = arr[l];
    int i = l, j = h;
    while(i < j){
        do{
            i++;
        }while(arr[i] <= p);

        do{
            j--;
        }while(arr[j] > p);

        if(i < j){
            swap(arr[i++], arr[j--]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int l, int h){
    if(l < h){
        int p = pivot(arr, l, h);
        quickSort(arr, l, p);
        quickSort(arr, p+1, h);
    }
}

int main(){
     int n; 
    cin >> n;

    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    quickSort(vec, 0, n);

    for(int num : vec) cout << num << " ";
    return 0;
}