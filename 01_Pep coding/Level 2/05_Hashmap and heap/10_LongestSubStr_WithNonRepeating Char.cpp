// Longest Substring With Non Repeating Characters
// https://nados.io/question/longest-substring-with-non-repeating-characters?zen=true

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

int solution(string str){
    // map<char, idx>
    unordered_map<char, int> mp;
    int i  = 0, j = 0, idx = 0;
    int len = INT_MIN;
    while(true){
        //Acquire till you find a repeating characher
        while(i < str.size()){
            char ch = str[i];
            if(mp.find(ch) != mp.end()) {
                idx = mp[ch]; //index of prev occurance of char
                break;
            }
            mp[ch] = i;
            i++;
        }
        //Collect ans
        len = max(len, i-j);
        if(i == str.size()) break;
        //Release till you find the prev occurance of repeating character
        while(j <= idx){
            char ch = str[j];
            mp.erase(ch);
            j++;
        }
    }
    return len;
}

int main(){
	string str;
	cin>>str;
	cout <<solution(str);
}