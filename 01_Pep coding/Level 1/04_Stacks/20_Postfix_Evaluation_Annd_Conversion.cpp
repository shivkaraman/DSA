
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int giveResult(int n1, int n2, char c){
    switch(c){
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

int postfixEvaluation(string postfix){
    string infix;
    stack<int> s;
    for(char &ch : postfix){
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            int n2 = s.top();
            s.pop();
            int n1 = s.top();
            s.pop();
            int res = giveResult(n1, n2, ch);
            s.push(res);
        }
        else{
            s.push(ch-'0');
        }
    }
    return s.top();
}

string postfixToInfix(string postfix){
    stack<string> s;
    for(char &ch  : postfix){
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            string oprnd2 = s.top();
            s.pop();
            string oprnd1 = s.top();
            s.pop();
            s.push('(' + oprnd1 + ch + oprnd2 + ')');
        }
        else{
            string oprnd(1, ch);
            s.push(oprnd);
        }
    }
    return s.top();
}

string postfixToPrefix(string postfix){
    stack<string> s;
    for(char &ch : postfix){
         if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            string oprnd2 = s.top();
            s.pop();
            string oprnd1 = s.top();
            s.pop();
            s.push(ch + oprnd1 + oprnd2);
        }
        else{
            string oprnd(1, ch);
            s.push(oprnd);
        }
    }
    return s.top();
}

int main(){
    string postfix;
    cin>>postfix;

    cout<<postfixEvaluation(postfix)<<endl; //Value
    cout<<postfixToInfix(postfix)<<endl;    //Infix expression
    cout<<postfixToPrefix(postfix)<<endl;   //Prefix expression
    return 0;
}