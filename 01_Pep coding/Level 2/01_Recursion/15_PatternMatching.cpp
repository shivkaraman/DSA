/*
1. You are given a string and a pattern. 
2. You've to check if the string is of the same structure as pattern without using any regular 
     expressions.

Sample Input
    graphtreesgraph
    pep
Sample Output
    p -> graph, e -> trees, . 

*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

/*
string- graphtreesgraph
pattern - pep

Level - char of pattern
option - part of string to be mapped with char of string
*/
void patternMatching(string str, string pattern, map<char, string> mp, string origPattern){
    if(pattern.size() == 0){
        if(str.size() == 0){
            for(int i  = 0; i < origPattern.size(); i++){
                char ch = origPattern[i];
                if(mp.find(ch) != mp.end()){
                    cout << ch << "->" << mp[ch] << endl;
                    mp.erase(ch);
                }
            }
        }
        return;
    }
    char ch = pattern[0];
    string rop = pattern.substr(1); //rest of pattern

    //If ch is already mapped to a string -> Check if currennt string's beginning contains the mapped string and proceed, else return
    if(mp.find(ch) != mp.end()){
        string mappedStr = mp[ch];
        if(str.size() >= mappedStr.size()){
            string check = str.substr(0, mappedStr.size());
            string ros = str.substr(mappedStr.size());
            if(mappedStr == check)
                patternMatching(ros, rop, mp, origPattern);
        }

    }
     //ch is not mapped -> Map a part of sting to ch
    else{
        for(int i = 0; i < str.size(); i++){
            string strMap = str.substr(0, i+1);
            string ros = str.substr(i+1);
            mp[ch] = strMap;
            patternMatching(ros, rop, mp, origPattern);
            mp.erase(ch);
        }
    }

}

int main(){
    string str, pattern;
    std :: cin >> str >> pattern;

    map<char, string>mp;
    patternMatching(str, pattern, mp, pattern);
}