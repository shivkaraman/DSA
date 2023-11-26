/*
https://nados.io/question/isomorphic-strings?zen=true

    str 1->  a   b   a   c   b   a
             |   |   |   |   |   |
             v   v   v   v   v   v
    str 2->  x   y   x   z   y   x

The above string is isomorphic as 
    a -> x
    b -> y
    c -> z

    str 1->  a   b   a   c   b   a
             |   |   |   |   |   |
             v   v   v   v   v   v
    str 2->  x   y   x   y   y   x
The above strings are not ispomorphic coz here both c and b are mapped to y(There should bo only one to one mapping)

To insure this property instead of mapping chars of str1-> str2 we map str2->str1
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()) return false;
    unordered_map<char, char> mp;
    for(int i = 0; i < s.length(); i++){
        auto it = mp.find(t[i]);
        if(it == mp.end()) mp[t[i]] = s[i];
        else if(it->second != s[i]) return false;
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