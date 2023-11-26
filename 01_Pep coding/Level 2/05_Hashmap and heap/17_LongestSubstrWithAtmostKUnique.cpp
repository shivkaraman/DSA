// https://nados.io/question/longest-substring-with-at-most-k-unique-characters?zen=true

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int solution(string s, int k) {
	unordered_map<char, int> mp;
	int i = 0, j = 0;
	int unique = 0, ans = 0;
	while(true){
		bool flag1 = false, flag2 = false;
		//Acquire till unique <= k
		while(i < s.size()){
			flag1 = true;
			char ch =s[i];
			if(mp.find(ch) == mp.end()) unique++;
			if(unique > k){
				unique--;
				break;
			}
			mp[ch]++;
			i++;
		}
		//Collecting ans
		ans = max(ans, i-j);
		//Release until a unique char is released
		while(j < i){
			flag2 = true;
			char ch = s[j++];
			if(mp[ch] == 1){
				mp.erase(ch);
				unique--;
				break;
			}
			else mp[ch]--;
		}
		if(!flag1 && !flag2) break;
	}
	return ans;
}



int main() {
	string str;
	getline(cin, str);
	int k;
	cin >> k;
	cout << solution(str, k);
}