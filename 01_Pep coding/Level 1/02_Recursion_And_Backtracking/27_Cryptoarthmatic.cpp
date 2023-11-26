#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    if(n1 + n2 == n3)
        return true;
    return false;
}

void display(map<char, int> mp){
    for(auto &p : mp)
        cout << p.first << "-" << p.second << " ";
    cout << endl;
}
//Level - Unique char of the strings
//Options - Assign any digit 0-9 to the character
void solution(map<char, int> mp, string unique, string s1, string s2, string s3, int idx, vector<bool> visited){
    if(idx == unique.size()){
        if(additionSuccess(s1, s2, s3, mp)){
            display(mp);
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(visited[i] != true){
            visited[i] = true;
            mp[unique[idx]] = i;
            solution(mp, unique, s1, s2, s3, idx+1, visited);
            visited[i] = false;
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

    vector<bool> visited(10, false);
    solution(mp, unique, s1, s2, s3, 0, visited);
    return 0;
}