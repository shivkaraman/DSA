/*
1. You are given a word (may have one character repeat more than once).
2. You are required to generate and print all arrangements of these characters. 

Sample Input
    aabb

Sample Output
    aabb
    abab
    abba
    baab
    baba
    bbaa
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;
/*
//* We use permutation from combination techneque
//* Here there are n boxex and n items 
//* ie n=r
//* 
//* 
//* So there is no option for the box to reject any item from placing into it
//* Only option is to place which item
//* 
//* ALso since there are duplicacies in input (ie aabb -> 2a's and 2b's), if we follow the standard PERMUTATION2 method
//* Duplicacy in final answer will be found as shown below
//* 
//* input: aabb
//* 
//*     b2    a---  a--- b---  b---
//*              \  \   |   /
//*              a\ a\  |b /b
//*                 \ \ | /
//*     b1            ___   ___   ___  ___
//* 
//* To avoid that we can create a frequency map of each character so that there is options available for unique characters
//* 
//*     b2     a_ _ _ |a1b2    b _ _ _ | a2b1
//*                    \        /
//*                    a\      /b
//*                      \    /        
//*     b1            __ __ __ __ | a2b2
//* 
//* 
//* LESSON LEARNT : IF THERE ARE DUPLICACIES IN INPUT ALWAYS CREATE FREQUENCY MAPS

*/

// Level - box
// item - which item
void permutation(map<char, int> &FreqMap, int boxNo, int tbox, string asf){
    if(boxNo == tbox+1){
        cout << asf << endl;
        return;
    }
    for(auto &it : FreqMap){
        if(it.second > 0){
            it.second--;
            permutation(FreqMap, boxNo+1, tbox, asf + it.first);
            it.second++;
        }
    }
}

int main(){
    string str;
    cin >> str;

    map<char, int> FreqMap; 
    for(char &ch : str){
            FreqMap[ch]++;
    }
    permutation(FreqMap, 1, str.size(), "");
}