/*
1. You are given a string of length n.
2. You have to print all the palindromic permutations of the given string.
3. If no palindromic permutation exists for the given string, print "-1".

Sample Input
    aaabb

Sample Output
    ababa
    baaab

//*  Approach
//*  1. Find the frequency of each alphabet in given string
//*  2. Divide the frequency of each by 2 and find the aplhabets with odd frequench
//*  3. Now generate all substings of string(with halp the frequency of alphabets)
//*  5. If no of odd freq character is >1, then palincromic permutations cannot be printed
//*  6. print the string + oddChar + reverse(string) -> palindromic permutation
*/

#include<iostream>
#include<algorithm>
#include<map> 
#include<algorithm> 
using namespace std;


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