/*
1. You are given an array(arr) of N numbers.
2. You have to select three indices i,j,k following this condition '
    X = arr[i] ^ arr[i+1] ^ .. ^ arr[j-1]
    Y = arr[j] ^ arr[j+1] ^ .. ^ arr[k]
    X=Y
3. You have to print the number of triplets where X is equal to Y.

Sample Input
    3
    1 2 3
Sample Output
    2
*/
#include <bits/stdc++.h>
using namespace std;
/*
If XOR of sequence of numbers ni.....nk = 0
And if the number sequence is divided into two parts keeping j as midpoint (i < j <= k)
ni .....n(j-1) and nj.......nk, then
XOR of ni---n(j-1) = XOR of nj.....nk

Total no of partitions = no of elements from i+1 to k
                       = k-i
*/
void solution(vector<int> &arr){
    int count = 0;
    for(int i = 0; i  < arr.size(); i++){
        int XOR = arr[i];
        for(int k = i+1; k < arr.size(); k++){
            XOR ^= arr[k];
            if(XOR == 0)
                count += (k-i);
        }
    }
    cout << count;
}

int main() {
	int n = 0;
	cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < arr.size(); i++){
        cin>>arr[i];
    }
    solution(arr);
    return 0;
}