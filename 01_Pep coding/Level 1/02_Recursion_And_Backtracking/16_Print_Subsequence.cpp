// 1. You are given a string str.
// 2. Complete the body of printSS function - without changing signature - to calculate and print all subsequences of str.

#include <iostream>
using namespace std;

//level -> strings
//option->to add first char or not
void printSS(string ques, string ans){
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    
    char ch=ques[0];
    string ros=ques.substr(1);

    printSS(ros,ans+"");
    printSS(ros,ans+ch);
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}