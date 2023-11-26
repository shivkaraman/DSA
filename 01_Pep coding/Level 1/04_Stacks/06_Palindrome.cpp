//Given a string with a and b and a character X which represents the middle of the string. Check if the linked list is palindrome
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<char> S;
    string str;
    cin>>str;
    int i;
    for(i=0; str[i] != 'X'; i++){
        S.push(str[i]);
    }
    i++;
    while(!S.empty() && i != str.length()){
        if(S.top() != str[i]){
            cout<<"Not Palindrome"<<endl;
            break;
        }
        S.pop();
        i++;
    }
    if(S.empty())
        cout<<"Palindrome"<<endl;
    return 0;
}