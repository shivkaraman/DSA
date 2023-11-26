/*
Simple Funda
    1. Postfix -> operand1 operand2 operator
    2. Prefix --> operator operand1 operand2     
*/

#include <iostream>
#include <stack>
using namespace std;

int precedence(char c){
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void   processing(stack<string> &postfix, stack<string> &prefix, char op){
    string post2 = postfix.top();
    postfix.pop();
    string post1 = postfix.top();
    postfix.pop();
    postfix.push(post1 + post2 + op);

    string pre2 = prefix.top();
    prefix.pop();
    string pre1 = prefix.top();
    prefix.pop();
    prefix.push(op + pre1 + pre2);
}

void InfixConversion(string infix){
    stack<string> prefix, postfix;
    stack<char> oper;
    for(char &ch : infix){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            string oprnd(1, ch);
            prefix.push(oprnd);
            postfix.push(oprnd);
        }
        else if(ch == '('){
            oper.push(ch);
        }
        else if(ch == ')'){
            while(oper.top() != '('){
                char op = oper.top();
                oper.pop();

                processing(postfix, prefix, op);
            }
            oper.pop();
        }
        else{
            while(!oper.empty() && precedence(ch) <= precedence(oper.top())){
                char op = oper.top();
                oper.pop();

                processing(postfix, prefix, op);
            }
            oper.push(ch);
        }
    }
    while(!oper.empty()){
        char op = oper.top();
        oper.pop();

        processing(postfix, prefix, op);
    }
    cout<<prefix.top()<<endl;
    cout<<postfix.top()<<endl;
}

int main(){
    string infix;
    cin>>infix;

    InfixConversion(infix);
    return 0;
}