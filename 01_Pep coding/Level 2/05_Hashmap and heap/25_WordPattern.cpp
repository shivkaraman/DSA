// https://nados.io/question/word-pattern?zen=true
//this is same question as prev one but here char of s1 is mapped to a word of s2

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<string, char> mp;
    int i = 0, j = 0;
    while(i < s.length()){
        string word;
        while(j < t.length() && t[j] != ' '){
            word.push_back(t[j++]);
        }
        j++;
        auto it = mp.find(word);
        if(it == mp.end()) mp[word] = s[i];
        else if(it->second != s[i]) return false;
        i++;
    }
    return true;
}

int main() {
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  int ans = isIsomorphic(str1, str2);
  if (ans == 1) {
    cout << "true";
  }
  else {
    cout << "false";
  }

}