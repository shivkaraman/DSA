// https://leetcode.com/problems/scramble-string/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

//Using recursion -> WE can optimize this to use si and ei instead of substr function to optimize the time complexity
unordered_set<string> s; 
bool isScramble(string s1, string s2){
    if(s1 == s2) return true;
    if(s1.size() != s2.size()) return false;

    //Memorization
    if(s.find(s1+s2) != s.end()) return false;

    for(int i = 1; i < s1.size(); i++){ //We can split anywhere
        string x1 = s1.substr(0, i);
        string y1 = s1.substr(i);

        string x2 = s2.substr(i);
        string y2 = s2.substr(i);

        //No swap
        bool check1 = isScramble(s1.substr(0, i), s2.substr(i));
        bool check2 = isScramble(s2.substr(i), s2.substr(i));

        //Swap
        if(!(check1 && check2)){
            check1 = isScramble(s1.substr(0, i), s2.substr(s2.size()-i));
            check2 = isScramble(s1.substr(i), s2.substr(0, s2.size()-i));
        }

        if(check1 && check2) return true;
    }
    s.insert(s1+s2);
    return false;
}

unordered_map<string, bool> mp;
bool isScramble2(string word1, string word2, int si1, int si2, int len) {
    string s1 = word1.substr(si1, len);
    string s2 = word2.substr(si2, len);

    string key = s1 + s2;
    if (mp.find(key) != mp.end()) return mp[key];
    if (s1 == s2){
        mp[key] = true;
        return true;
    }

    for (int i = si1; i < len; i++) { // We can split anywhere
        // No swap
        bool check1 = isScramble2(word1, word2, si1, si2, i);
        bool check2 = isScramble2(word1, word2, si1 + i, si2 + i, len-i);
        // Swap
        if (!(check1 && check2)) {
            check1 = isScramble2(word1, word2, si1, si2+len-i, i);
            check2 = isScramble2(word1, word2, si1+i, si2, len-i);
        }
        if (check1 && check2) {
            mp[key] = true;
            return true;
        }
    }

    mp[key] = false;
    return false;
}

bool isScramble2(string word1, string word2){
    return isScramble2(word1, word2, 0, 0, word2.size());
}

int main(){
    cout << isScramble2("sqksrqzhhmfmlmqvlbnaqcmebbkqfy", "abbkyfqemcqnblvqmlmfmhhzqrskqs");
    // cout << isScramble2("great", "rgeat");
    // cout << isScramble2("great", "eatrg");
}