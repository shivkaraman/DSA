/*
1. You are given an array of distinct integers.
2. You have to print all pairs of integers in the array whose XOR value is minimum.

Sample Input
    4 
    2 0 5 7
Sample Output
    0, 2
    5, 7

For given set of numbers, min of XOR of all the pairs is -> min of XOR of consecutive pairs in sorted array 
	PROPERTY USED :  a <= b <= c
		then 	a^b    <    a^c
			      OR
			b^c    <    a^c
		a^c IS NEVER LESS THAN a^b and b^c
    
So this way we are avoiding checking a^c in every pair of a <= b <= c
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void solution(vector<int>& arr){
    sort(arr.begin(), arr.end());
    int minXOR = INT_MAX;
    string ans = "";
    for(int i = 0; i < arr.size()-1; i++){
        int XOR = (arr[i] ^ arr[i+1]);
        if(XOR < minXOR){
            minXOR = XOR;
            ans = to_string(arr[i]) + ", " + to_string(arr[i+1]) + "\n";
            continue;
        }
        else if(minXOR == XOR){
            ans += to_string(arr[i]) + ", " + to_string(arr[i+1]) + "\n";
        }
    }
    cout << ans << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    solution(arr);
    return 0;
}