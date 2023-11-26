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
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Level  - Item
Option - boxes

In this approach we are allowed to place the repeating character only in boxes 
after the prev char was placed

LESSON LEARNT : 
PERMUTATION 1 : TO AVOID DUPICACY WE PLACE THE DUPLICATE ITEM ONLY IN BOXES AFTER WHICH PREV DUPLICATE ITEM WAS PLACED
PERMUTATION 2 : TO AVOID DUPLICACY WE CREATE FREQUENCY MAP 
*/

void permutation(string str, int charNo, vector<char> boxes, int nonEmpty, unordered_map<char, int> mp){
    if(charNo == str.size()){
        for(char &ch : boxes)
            cout << ch;
        cout << endl;
        return;
    }
    int boxNo; 
    if(mp.find(str[charNo]) == mp.end())
        boxNo = 0;
    else
        boxNo = mp[str[charNo]];

    for(; boxNo < boxes.size(); boxNo++){
        if(boxes[boxNo] == '-'){
            boxes[boxNo] = str[charNo];
            mp[str[charNo]] = boxNo;
            permutation(str, charNo+1, boxes, nonEmpty+1, mp);
            mp.erase(str[charNo]);
            boxes[boxNo] = '-';
        }
    }
}
int main(){
    string str;
    cin >> str;

    vector<char>boxes(str.size(), '-');
    //map<char, prev occurance of char>
    unordered_map<char, int> mp;
    permutation(str, 0, boxes, 0, mp);
}