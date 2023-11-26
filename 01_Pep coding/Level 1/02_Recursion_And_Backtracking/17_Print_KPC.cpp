
#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

//level -> keys
//option-> which char correspondig to key should be added
void printKPC(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = ques[0];
    string ros = ques.substr(1);
    int idx=ch-'0';
    for(char &c : codes[idx]){
        printKPC(ros,ans+c);
    }
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}