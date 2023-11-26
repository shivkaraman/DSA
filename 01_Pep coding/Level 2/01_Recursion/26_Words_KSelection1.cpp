/*
1. You are given a word (may have one character repeat more than once).
2. You are given an integer k.
2. You are required to generate and print all ways you can select k distinct characters out of the 
    word.

Sample Input
    aabbbccdde
    3
Sample Output
    abc
    abd
    abe
    acd
    ace
    ade
    bcd
    bce
    bde
    cde



Level : Box
Option : Item Included/Item Not Included
*/

#include <bits/stdc++.h>
using namespace std;

void combination(int i, string ustr, int totsel, int k, string asf ){
    if(i == ustr.size()){
        if(totsel == k)
            cout << asf << endl;
        return;
    }
    combination(i+1, ustr, totsel+1, k, asf + ustr[i]);
    combination(i+1, ustr, totsel, k, asf);
}

int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    
    set<char> unique;
    string ustr="";
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(unique.find(ch)==unique.end()){
            unique.insert(ch);
            ustr+=ch;
        }
    }
    combination(0, ustr, 0, k, "");
    return 0;
}