// https://nados.io/question/count-distinct-elements-in-every-window-of-size-k?zen=true
// logic -> 1. Push  first k-1 elements
//          2. From kth element  -> push	(Acquire)
//                                  print
//                                  remove  (Release)
// This is called as acquire and release strategy => VVIP useed in many hashmap questions -> all solutions which use this have o(n) time

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> &arr, int k){
	//map<val, freq>
	unordered_map<int, int> mp;
    for(int i = 0; i < k-1; i++){
		mp[arr[i]]++;
	}
	vector<int> ans;
	for(int i = k-1; i < arr.size(); i++){
		mp[arr[i]]++;
		ans.push_back(mp.size());

        int remIdx = i - (k-1);
		if(mp[arr[remIdx] == 1]) mp.erase(arr[remIdx]);
		else mp[arr[remIdx]]--;
	}
	return ans;
}

int main (){
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < arr.size(); i++){
	    cin >> arr[i];
	}
	int k = 0;
	cin >> k;
	
	vector<int> ans = solution(arr, k);
	for(int a : ans){
		cout << a << " ";
	}
	return 0;
}