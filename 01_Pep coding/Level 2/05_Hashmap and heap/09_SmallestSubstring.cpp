// Smallest Substring Of A String Containing All Unique Characters Of Itself
// https://nados.io/question/smallest-substring-of-a-string-containing-all-unique-characters-of-itself?zen=true
// Solution is same as prev question, but here we map s1 itself instead of s2

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int Solution(string s){

	unordered_set<char, int> unique;
	for(char ch : s) unique.insert(ch);

	int len = INT_MAX;
	int i = -1, j = -1;
	unordered_map<char, int> mp;

	while (true){	//O(n)
		bool flag1 = false, flag2 = false;
		//Acquire -> Acquire till we get all desired chars present in s2
		int size = s.size();
		while (i < size && mp.size() < unique.size()){
			i++;
			char ch = s[i];
			
			mp[ch]++;  
			flag1 = true;
		}
		//Collect answers and release -> Release all unwanted characters
		int plen = i-j+1; //potential length
		while(j < i && mp.size() == unique.size()){
			plen--;
			j++;

			char ch = s[j];
			auto it = mp.find(ch);
			if(it->second == 1) mp.erase(it);
			else it->second--;

			flag2 = true;
		}
		if(plen < len) len = plen;
		if(!flag1 && !flag2) break;
	}
	
	return len == INT_MAX ? 0 : len;
}

int main() {
	string s, s2;
	cin >> s;
	
	cout << Solution(s) << endl;
}		