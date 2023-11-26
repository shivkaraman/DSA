// 1. You are given a string str.
// 2. Complete the body of getSS function - without changing signature - to calculate all subsequences of str.
/*
if n==3
s=abc
Subsequences :
EXPECTATION-> gss(s)                    FAITH                                      F-E
GSS  prints all subsequence     GSS prints all subsequencs of             gss(abc) from gss(bc)
of abc                                    bc                      gss(bc) gives { _ _ _ , _ _ c , _ b _ , _ b c }
    _ _ _                               _ _ _                     If we feed gss(bs) to vector <string> , and then add 
    _ _ c                               _ _ c                     'a' at beginning of each string returned by gss(bc)
    _ b _                               _ b _                     we get all sub
    _ b c                               _ b c
    a _ _
    a _ c
    a b _
    a b c

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// abc-> ---,--c,-b-,-bc,a--,a-c,ab-,abc
// bc -> --,-c,b-,bc
vector<string> gss(string s){
    if(s.size()==0){
        vector <string> base = {""};    //This is  vvip ,for a string of size zero no of substring == 1 ie an empty string
        return base;                    
    }
    char ch = s[0];                     // a (first char of string)
    string ros = s.substr(1);           // bc (rest of string)

    vector <string> faith =gss(ros);    // [--,-c,b-,bc]

    vector <string> subseq;
    for(string &str : faith)
        subseq.push_back(""+str);       // [---,--c,-b-,-bc]

    for(string &str : faith)
        subseq.push_back(ch+str);       // [---,--c,-b-,-bc,a--,a-c,ab-,abc]

    return subseq;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string &str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}