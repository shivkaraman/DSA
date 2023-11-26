/*

1. You are given a string, which represents an expression having only opening and closing parenthesis.
2. You have to remove minimum number of parenthesis to make the given expression valid.
3. If there are multiple answers, you have to print all of them.

Sample Input
    ()())()
Sample Output
    (())()
    ()()()
*/
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

bool isValid(string str){
    stack<char> st;
    int i = 0;
    do{
        if(str[i] == '(')
            st.push('(');
        else if(str[i] == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else 
                st.push(')');
        }
        i++;
    }while(i < str.size());
    return st.empty();
}

int howMuch(string str){
    stack<char> st;
    int i = 0;
    do{
        if(str[i] == '(')
            st.push('(');
        else if(str[i] == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(')');
        }
        i++;
    }while(i < str.size());
    return st.size();
}
//Level - string of perenthesis
//Optiion - which perenthesis to remove
//Map is used to avoid repetive answer printing
void removeInvalid(string str, int i, int hm, unordered_map<string, bool> &mp){
    if(hm == 0){
        if(isValid(str)){
            if(mp.find(str) == mp.end()){
                mp.insert({str, true});
                cout << str << endl;
            }
        }
        return;
    }
    for(int i = 0; i < str.size(); i++){
        string left = str.substr(0, i);
        string right = str.substr(i+1);
        removeInvalid(left+right, i, hm-1, mp);
    }
    
}

int main(){

    string str;
    cin >> str;

    int hm = howMuch(str);
    unordered_map<string, bool> mp;
    removeInvalid(str, 0, hm, mp);
}