// 1. You are given a string str.
// 2. You are required to find the character with maximum frequency.

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<char, int> m;
    string s;
    cin >> s;
    
    for(char &c : s){
        m[c]++;
    }
    char c;
    int mx{};
    for(auto &p : m){
        if(p.second > mx){
            mx = p.second;
            c = p.first;
        }
    }
    cout << c << endl;
    return 0;
}