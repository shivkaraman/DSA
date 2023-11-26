// 1. You are given a number n1, representing the size of array a1.
// 2. You are given n1 numbers, representing elements of array a1.
// 3. You are given a number n2, representing the size of array a2.
// 4. You are given n2 numbers, representing elements of array a2.
// 5. You are required to find the intersection of a1 and a2. To get an idea check the example below:
 
// if a1 -> 1 1 2 2 2 3 5
// and a2 -> 1 1 1 2 2 4 5
// intersection is -> 1 1 2 2 5

// Note -> Don't assume the arrays to be sorted. Check out the question video.

// Constraints
// 1 <= n1, n2 <= 100
// 0 <= a1[i], a2[i] < 10
// Time complexity should be O(n)

#include<bits/stdc++.h>
using namespace std;

int main(){
	unordered_map<int, int> mp;
	int n1;
	cin >> n1;
	int arr1[n1];
	for (int i = 0; i < n1; i++){
		cin >> arr1[i];
		mp[arr1[i]]++;
	}
	int n2;
	cin >> n2;
	int arr2[n1];
	for(int i = 0; i < n2; i++){
		cin >> arr2[i];
		auto it = mp.find(arr2[i]);
		if(it != mp.end()){
			if(it->second > 0){
				cout << it->first << endl;
				it->second--;
			}
		}
	}
}