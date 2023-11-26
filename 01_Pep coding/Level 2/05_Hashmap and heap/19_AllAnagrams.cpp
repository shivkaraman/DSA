// https://nados.io/question/find-all-anagrams-in-a-string?zen=true
// Two strings having the same frequency for each of its char are anagrams OR if we can form one string by arranging the characters of another string
//THis question has used exact same code of 08_smallest_substring (smallestt substr of s1 containing all chars of s2) and modified it a little bit while collecting answers

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> findAnagrams(string s1, string s2) {
	unordered_map<char, int> mp1, mp2;
	for(char ch : s2) mp2[ch]++;
	int i = -1, j = -1;
	int dmatch = s2.size();
	int match = 0;
	int size = s1.size();
	vector<int> ans;
	while(true){
		bool flag1 = 0, flag2 = 0;
		//Acquire till all chars of s2 are mapped
		while(i < size && match < dmatch){
			char ch = s1[++i];
			if(mp2.find(ch) == mp2.end()) continue;
			mp1[ch]++;
			if(mp1[ch] <= mp2[ch]) match++;
			flag1 = true;
		}		
		//Release until a useful character is released
		while(j < i && dmatch == match){
			char ch = s1[++j];

			auto it = mp1.find(ch);
			if(it == mp1.end()) continue;
			if(it->second-1 < mp2[ch]){
				if(i-j+1 == s2.size()){//Collecting ans -> WKT dmatch == match, and if substr.size (i-j+1) == s2.size then clearly substr is an anagram of s2
					ans.push_back(j);
				}
				match--;
			} 
			//Releasing answer
			if(it->second == 1) mp1.erase(ch);
			else it->second--;
			flag2 = true;

		}
		if(!flag1 && !flag2) break;
	}
	return ans;
}

int main() {
	string s;
	string p;
	cin >> s >> p;
	vector<int> ans = findAnagrams(s, p);
	cout << ans.size() << endl;
	for(int i : ans) cout << i << " ";
}