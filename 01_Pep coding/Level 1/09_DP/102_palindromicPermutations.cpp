#include<iostream>
#include<algorithm>
#include<unordered_map> 
#include<algorithm> 
using namespace std;

bool isPalindrome(string str){
    string temp =str;
    reverse(str.begin(), str.end());
    return str == temp;
}

void palindromicPermutation(int i, int len, unordered_map<char, int> mp, char odd, string asf){
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
    unordered_map<char, int> mp;
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
    palindromicPermutation(0, length, mp, odd, "");
}