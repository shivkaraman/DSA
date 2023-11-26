/*
1. You are given a number n, representing the number of elements.
2. You are given n numbers, representing the contents of array of length n.
3. You are required to print the length of longest bitonic subsequence of array.
Note -> bitonic subsequence begins with elements in increasing order, followed by elements in decreasing order.

Sample Input
10 
10 22 9 33 21 50 41 60 80 1

Sample Output
7
*/
#include<iostream>
#include<vector>
using namespace std;

int longestBitnicSubseq(vector<int> arr, int n){
    vector<int> lis(n, 0); //Longest increasing subsequence
    lis[0] = 1;
    for(int i = 1; i < n; i++){
        int mx = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i])
                mx = max(mx, lis[j]);
        }
        lis[i] = mx + 1;
    }
    
    vector<int> lds(n, 0); //Longest decreasing subsequence
    lds[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--){
        int mx = 0;
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[i])
                mx = max(mx, lds[j]);
        }
        lds[i] = mx + 1;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, lis[i]+lds[i]-1);
    }
    return ans;
}

int main(){
    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << longestBitnicSubseq(arr, n);
    return 0;
}
