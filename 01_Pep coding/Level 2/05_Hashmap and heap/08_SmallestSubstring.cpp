// Smallest Substring Of A String Containing All Characters Of Another String
// https://nados.io/question/smallest-substring-of-a-string-containing-all-characters-of-another-string?zen=true
// https://www.youtube.com/watch?v=e1HlptlipB0&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=8

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

string Solution(string s1, string s2){
	if(s2.size() > s1.size()) return "";

	unordered_map<char, int> mp2;
	for(char ch : s2) 
		mp2[ch]++;

	int dcount = s2.size();			 //Desired match count
	int mcount = 0, i = -1, j = -1;  //match count
	int idx = 0, minL = INT_MAX;
	unordered_map<char, int> mp1;

	while (true){
		bool flag1 = false, flag2 = false;
		//Acquire uniil all chars of s2 are acquired
		int size = s1.size();
		while (i < size && mcount < dcount){
			i++;
			char ch = s1[i];
			if(mp2.find(ch) == mp2.end()) continue; //Hashing only chars which are part of s2
			
			mp1[ch]++;  
			if(mp1[ch] <= mp2[ch]) mcount++;
			flag1 = true;
		}
		//Release until a useful character is released
		int len = i-j+1;
		int pidx = j; //Potential idx
		while(j < i && dcount == mcount){
			j++;
			len--;
			pidx++;

			char ch = s1[j];
			auto it = mp1.find(ch);
			if(it == mp1.end()) continue;	//Chae not a part of s2

			if(it->second-1 < mp2[ch]) mcount--; 
			
			if(it->second == 1) mp1.erase(it);
			else it->second--;

			flag2 = true;
		}
		if(len < minL){
			minL = len;
			idx = pidx;
		}
		if(!flag1 && !flag2) break;
	}
	
	return minL == INT_MAX ? "" : s1.substr(idx, minL);
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	cout << Solution(s1, s2) << endl;
}		