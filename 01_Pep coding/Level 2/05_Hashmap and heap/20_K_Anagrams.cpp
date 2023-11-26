// https://nados.io/question/k-anagrams?zen=true
// Two strings are k anagrams if two strings become by replacing upto k characters in one string
// https://www.youtube.com/watch?v=VyQbl13RGiw&list=PL-Jc9J83PIiEp9DKNiaQyjuDeg3XSoVMR&index=20

// Check if two strings are k anagrams

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool areKAnagrams(string str1, string str2, int k) {
    if(str1.size() != str2.size()) return false;

	unordered_map<char, int> mp;
    for(char ch: str1) mp[ch]++;

    for(char ch: str2){
        if(mp.find(ch) != mp.end()) mp[ch]--;
    }
	int swapCount = 0;
    for(pair<char, int> p: mp){
		if(p.second > 0) swapCount+= p.second;
	}
	return swapCount <= k;
}

int main(){

	string str1;
	string str2;
	int k;
	cin >> str1 >> str2 >> k;
	if(areKAnagrams(str1, str2, k))
	    cout<<"true";
	else
	    cout<<"false";

}