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
*/
#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;

/*
Same as combination 2 
But here we are creating unique string (length x) from given string (length n)
We need to fing xCk
*/
void kselections(string unique, int k, int charIdx, int prevBox, int nonEmpty, vector<char> box){
    if(charIdx == unique.size()){
        if(nonEmpty == k){
            for(char &x : box)
                cout << x;
            cout << endl;
        }
        return;
    }
    for(int i = prevBox+1; i < box.size(); i++){
        if(box[i] == '-'){
            box[i] = unique[charIdx];
            kselections(unique, k, charIdx + 1, i, nonEmpty + 1, box);
            box[i] = '-';
        }
    }
    kselections(unique, k, charIdx + 1, prevBox, nonEmpty, box);
}

int main(){
    string str;
    cin >> str;
     
    int k;
    cin >> k;

    set<char> uset;
    string unique;
    for(char &ch : str){
        if(uset.find(ch) == uset.end()){
            uset.insert(ch);
            unique += ch;
        }
    }   
    vector<char> box(k, '-');
    kselections(unique, k, 0, -1, 0, box);

}