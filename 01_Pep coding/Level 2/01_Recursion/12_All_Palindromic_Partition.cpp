/*
1. You are given a string of length n.
2. You have to partition the given string in such a way that every partition is a palindrome.

Sample Input
    pep

Sample Output
    (p) (e) (p) 
    (pep) 
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string str){
    string temp = str;
    reverse(str.begin(), str.end());
    return str == temp;
}

void solution(string str, string asf){
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++){
        string temp = str.substr(0, i+1);
        if(isPalindrome(temp)){
            string ros = str.substr(i+1);
            solution(ros, asf + '(' + temp + ") ");
        }
    }
}

int main() {
    string str;    
    cin>>str;
    solution(str,"");
    return 0;
}