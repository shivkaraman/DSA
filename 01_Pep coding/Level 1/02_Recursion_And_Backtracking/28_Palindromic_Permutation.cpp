#include<iostream>
#include<algorithm>
#include<map> 
#include<algorithm> 
using namespace std;

bool isPalindrome(string str){
    string temp =str;
    reverse(str.begin(), str.end());
    return str == temp;
}
/*
For a given string, palidromic permtationns are possible only if 
    1. Frequency of each character of the string is even
    2. There exists zero or one character with odd frequency
method -
    1. Half the frequency of all the characters of the string(except the one with odd frequency)
    2. Print all permtation of the string consisting of half no characters of original string
    3. Take reverse of each permutation, append char of odd freq to each permutation and append the reverse of permutation

        eg - aabbc
            half - ab odd -
            permutatins - ab, ba
            palindromic permutation - abcba, bacab

*/
void palindromicPermutation(int i, int len, map<char, int> mp, char odd, string asf){
    if(i > len){
        string temp = asf; 
        reverse(asf.begin(), asf.end());
        cout << temp + odd + asf << endl;
        return;
    }
    for(auto &p: mp){
        if(p.second > 0){
            p.second --;
            palindromicPermutation(i+1, len, mp, odd, asf + p.first);
            p.second++;
        }
    }
}

int main(){
    string str;
    cin >> str;
    map<char, int> mp;
    for(char &ch: str){
        if(mp.find(ch) == mp.end())
            mp[ch] = 1;
        else    
            mp[ch]++;
    }
    int odds{}, length{};
    char odd;
    for(auto &p: mp){
        if(p.second % 2 == 1){
            odds++;
            odd = p.first;
        }
        p.second /= 2;
        length += p.second;
    }
    palindromicPermutation(1, length, mp, odd, "");
}