/*
    an = a0 + (n-1) d
=>  d = an-a0 / n-1
*/

#include <iostream>
#include <unordered_set>
#include <cmath>
#include <vector>
using namespace std;

bool solution(vector<int> arr) {
    unordered_set<int> s;
    int mn = INT_MAX, mx = INT_MIN; 
    for(int num : arr){
        mx = max(mx, num);
        mn = min(mx, num);
        s.insert(num);
    }
    int d = (mx - mn) / (arr.size() - 1);

    for(int i = 0; i < arr.size(); i++){
        if(s.find(mn + i*d) == s.end()) return false;
    } 
    return true;
}

int main() {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++){
		int val;
		cin>>val;
		arr[i] = val;
	}
	if(solution(arr))
	    cout<<"true";
	else
	    cout<<"false";
}   