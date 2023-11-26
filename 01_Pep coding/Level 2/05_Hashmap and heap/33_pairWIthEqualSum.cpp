// https://nados.io/question/pairs-with-equal-sum?zen=true
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<int>& arr, int n) {
	//map<sum, pair>
	unordered_map<int, pair<int, int>> mp;
	for(int i = 0 ; i < arr.size(); i++){
		for(int j = i+1; j < arr.size(); j++){
			int sum = arr[i] + arr[j];
			if(mp.find(sum) != mp.end()) return true;
			else mp[sum] = {arr[i], arr[j]};
		}	
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool ans = solution(arr, n);
	if (ans == 0) {
		cout << "false";
	} else {
		cout << "true";
	}
}