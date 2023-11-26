#include <iostream>
#include <vector>
// https://nados.io/question/check-if-an-array-can-be-divided-into-pairs-whose-sum-is-divisible-by-k?zen=true
// https://www.youtube.com/watch?v=BvKv-118twg&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=3
// if sum of (num1 % k) + (num2 % k) == k then num1+num2 is divisible by k

#include <unordered_map>
using namespace std;

bool solution(vector<int> &arr, int k){
	// map <val % k, val>
	unordered_multimap<int, int> mp;
	for(int &num : arr) mp.insert({num%k, num}); 
	
	for(int i = 0; i < k; i++){
		while(mp.find(i) != mp.end()){
			auto it = mp.find(i);
			mp.erase(it);

			auto it2 = mp.find(i == 0 ? 0 : k-i);
			if(it2 == mp.end()) return false;
			mp.erase(it2);
		}
	}
	return true;
}

/*
In this approach, we create a remainder frequency map where we store rem -> freq of rem
The solution is true onluy when the remainder frequency of 	
	1. 0 is even
	2. k/2 is even 
	3. freq (rem) = freq(k-rem)
*/
bool solution2(vector <int> &vec, int k){
	unordered_map<int, int> mp;
	//remainder fmap
	for(int &num : vec) mp[num % k]++;

	for(int &num : vec){
		int rem = num % k;

		if(rem == 0 || 2 * rem == k){
			if(mp[rem] % 2 != 0) return false;
		}
		else{
			int rFreq = mp[rem];
			int rmkFreq = mp[k - rem];
			if(rFreq != rmkFreq) return false;
		}
	}
	return true;
}

int main() {
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++){
		cin >> arr[i];
	}
	int k = 0;
	cin >> k;
	cout << boolalpha << solution2(arr, k);
	return 0;
}