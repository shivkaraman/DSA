// 1. You are given a string str. The string str will contains numbers only, where each number stands for a key pressed on a mobile phone.
// 2. The following list is the key to characters map :
//     0 -> .;
//     1 -> abc
//     2 -> def
//     3 -> ghi
//     4 -> jkl
//     5 -> mno
//     6 -> pqrs
//     7 -> tu
//     8 -> vwx
//     9 -> yz
// 3. When a key is pressed the character clicked(used) is unknown
// 3. Complete the body of getKPC function

// Sample Input
// 78
// Sample Output
// [tv, tw, tx, uv, uw, ux]

#include <bits/stdc++.h>
using namespace std;

// 578 --> [mtv, mtw, mtx, muv, muw, mux, ntv, ntw, ntx, nuv, nuw, nux, otv, otw, otx, ouv, ouw, oux]
//  78 --> [tv, tw, tx, uv, uw, ux]
vector <string> gkpc(vector <string> s ,string str){
    if(str.size()==0){
        vector <string> base={""};
        return base;
    }
    char ch=str[0];                         // 5
    string ros=str.substr(1);               // 78

    vector <string> res=gkpc(s,ros);        //[tv, tw, tx, uv, uw, ux]
    vector <string> kpc;

    int idx=ch-'0';                         
    for(char &temp : s[idx]){               // First run  --> mtv, mtw, mtx, muv, muw, mux
        for(string &temp2 : res)            // Second run --> ntv, ntw, ntx, nuv, nuw, nux
            kpc.push_back(temp+temp2);      // Third run  --> otv, otw, otx, ouv, ouw, oux
    }
    return kpc;
}

int main(){
    vector <string> s={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
    string str;
    cin>>str;
    
    vector <string> kpc=gkpc(s,str);
    int cnt = 0;

    cout << '[';
    for (string &str : kpc){
        if (cnt != kpc.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
    return 0;
}