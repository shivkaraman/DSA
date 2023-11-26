//Count Of Substrings Having All Unique Characters
// https://nados.io/question/count-of-substrings-having-all-unique-characters?zen=true

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

int solution(string str){
    // map<char, idx>
    unordered_map<char, int> mp;
    int i  = 0, j = 0, idx = 0;
    int len = 0, count = 0;
    while(true){
        //Acquire till you find a repeating characher
        while(i < str.size()){
            char ch = str[i];
            if(mp.find(ch) != mp.end()) {
                idx = mp[ch]; //index of prev occurance of char
                break;
            }
			len += i-j+1;//Acquire answer
            mp[ch] = i;
            i++;
        }
        if(i == str.size()) break;
        //Release till you find the prev occurance of repeating character
        while(j <= idx){
            char ch = str[j];
            mp.erase(ch);
            j++;
        }
    }
    return count;
}
 
int main(int argc,char** argv){
    string s;
    cin>>s;
    cout<<solution(s)<<endl;
}