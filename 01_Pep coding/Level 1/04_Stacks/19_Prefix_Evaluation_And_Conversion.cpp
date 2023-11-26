
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int giveResult(int n1, int n2, char op){
    switch(op){
        case '+' : 
            return n1+n2;
        case '-' : 
            return n1-n2;
        case '*' : 
            return n1*n2;
        case '/' : 
            return n1/n2;
        case '^' : 
            return n1^n2;
    }
    return -1;
}

int prefixEvaluation(string prefix){
    stack<int> oprnd;
    reverse(prefix.begin(), prefix.end());
    for(char &ch : prefix){
        if(ch >= '0' && ch <= '9'){
            oprnd.push(ch - '0');
        }
        else{
            int n1 = oprnd.top();
            oprnd.pop();
            int n2 = oprnd.top();
            oprnd.pop();
            int res = giveResult(n1, n2, ch);
            oprnd.push(res);
        }
    }
    return oprnd.top();
}

void prefixToInfix(string prefix){
    stack<string> infix;
    stack<string> postfix;
    reverse(prefix.begin(), prefix.end());
    for(char &ch : prefix){
        if(ch >= '0' && ch <= '9'){
            string s(1,ch);
            infix.push(s);
            postfix.push(s);
        }
        else{
            string s1, s2;
            s1 = infix.top();
            infix.pop();
            s2 = infix.top();
            infix.pop();
            infix.push('(' + s1 + ch + s2 + ')');

            s1 = postfix.top();
            postfix.pop();
            s2 = postfix.top();
            postfix.pop();
            postfix.push(s1 + s2 +  ch);
        }
    }
    cout<<infix.top()<<endl;
    cout<<postfix.top()<<endl;
}

int main(){
    string prefix;
    cin>>prefix;

    // cout<<prefixEvaluation(prefix)<<endl;
    prefixToInfix(prefix);
    return 0;
}
