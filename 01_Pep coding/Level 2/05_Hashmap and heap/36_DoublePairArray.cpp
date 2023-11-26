// https://nados.io/question/double-pair-array?zen=true
#include <iostream>
#include <unordered_set>
#include <cmath>
#include <vector>
using namespace std;

bool solution(vector<int>& arr) {
  	unordered_multiset<float> s;
	for(int &num : arr) s.insert(num);

	for(int num : arr){
		if(s.find(num) == s.end()) continue;
		auto it = s.find(num);
		s.erase(it);

		it = s.find(num / 2.0);
		auto it2 = s.find(num * 2.0);

		if (it != s.end()) s.erase(it);
		else if(it2 != s.end()) s.erase(it2);
		else return false;
	}
	return true;
}



int main(){
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	};

	bool ans = solution(arr);
	if (ans == 1) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}