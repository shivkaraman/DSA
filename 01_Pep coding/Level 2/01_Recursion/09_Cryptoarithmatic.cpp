/*
1. You are given three strings s1, s2 and s3.
2. First two are supposed to add and form third. s1 + s2 = s3
3. You have to map each individual character to a digit, so that the above equation holds true.     

Sample Input
    team
    pep
    toppr

Sample Output
    a-3 e-9 m-4 o-1 p-2 r-6 t-0 
    a-3 e-9 m-5 o-1 p-2 r-7 t-0 
    a-3 e-9 m-6 o-1 p-2 r-8 t-0 
    a-4 e-9 m-2 o-1 p-3 r-5 t-0 
    a-4 e-9 m-5 o-1 p-3 r-8 t-0 
    a-5 e-9 m-2 o-1 p-4 r-6 t-0 
    a-5 e-9 m-3 o-1 p-4 r-7 t-0 
    a-6 e-9 m-2 o-1 p-5 r-7 t-0 
    a-6 e-9 m-3 o-1 p-5 r-8 t-0 
    a-7 e-9 m-2 o-1 p-6 r-8 t-0 
*/

#include <bits/stdc++.h>
using namespace std;

bool additionSuccess(string s1, string s2, string s3, map<char, int> mp){
    string num1, num2, num3;
    for(char &ch : s1){
        if(mp[ch] == -1)
            return false;
        num1 += to_string(mp[ch]);
    }
    for(char &ch : s2){
        if(mp[ch] == -1)
            return false;
        num2 += to_string(mp[ch]);
    }
    for(char &ch : s3){
        if(mp[ch] == -1)
            return false;
        num3 += to_string(mp[ch]);
    }
    int n1 = stoi(num1);
    int n2 = stoi(num2);
    int n3 = stoi(num3);
    return(n1 + n2 == n3);
}

void display(map<char, int> mp){
    for(auto &p : mp)
        cout << p.first << "-" << p.second << " ";
    cout << endl;
}
//Level -> alphabet of "unique" stinrg
//options -> numbers 0-9
void solution(map<char, int> mp, string unique, string s1, string s2, string s3, int idx, vector<bool> usedNum){
    if(idx == unique.size()){
        if(additionSuccess(s1, s2, s3, mp)){
            display(mp);
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(usedNum[i] != true){
            usedNum[i] = true;
            mp[unique[idx]] = i;
            solution(mp, unique, s1, s2, s3, idx+1, usedNum);
            usedNum[i] = false;
            mp[unique[idx]] = -1;
        }
    }
}
int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    string unique;
    map<char, int> mp;
    for(char &ch: s1){
        if(mp.find(ch) == mp.end()){
            mp[ch] = -1;
            unique += ch;
        }
    }
    for(char &ch: s2){
        if(mp.find(ch) == mp.end()){
            mp[ch] = -1;
            unique += ch;
        }
    }
    for(char &ch: s3){
        if(mp.find(ch) == mp.end()){
            mp[ch] = -1;
            unique += ch;
        }
    }

    vector<bool> usedNum(10, false);
    solution(mp, unique, s1, s2, s3, 0, usedNum);
   
    return 0;
}