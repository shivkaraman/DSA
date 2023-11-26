// https://nados.io/question/longest-substring-with-exactly-k-unique-characters?zen=true

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

int solution(string s, int k){
    // map<char, freq>
    unordered_map<char, int> mp;
    int i = 0, j  = 0;
    int maxL = 0, unique = 0;
    while(true){
        //Acquire till unique == k
        while(i < s.size()){
            char ch = s[i];
            if(mp.find(ch) == mp.end()) unique++; 
            if(unique > k) break;
            mp[ch]++;
            i++;
        }
        unique--;
        //Collect answer
        maxL = max(maxL, i-j);
        if(i == s.size()) break;
        //Release till one unique element is removed 
        while(j < i){
            char ch = s[j++];//j is incrimented intensionally here coz say if unique element is removed and we break, we need to point to next element of unique
            if(mp[ch] == 1){
                mp.erase(ch);
                unique--;
                break;
            }   
            else mp[ch]--;          
        }
    }
    return maxL;
}

int main(int argc,char** argv){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout<< solution(s, k) << endl;
}