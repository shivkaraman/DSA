/*
1. Reverse the infix expression
2. Replace '(' by ')' and vice versa
3. Convert to postfix(with a few additionl set of rules)
4. Reverse the postfix expression
https://www.youtube.com/watch?v=gmlVZ68KRD8
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') 
        return true;
    return false;
}

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

string InfixToPostfix(string infix){
    stack<char> s;
    infix = '(' + infix + ')';
    string prefix;
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')){
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (s.top() != '('){
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else if(isOperator(infix[i])){
            //This is loop is to evaluate only '^' operator, If there are multiple ^ operators we pop the previous ones
            //This is because the associativity of ^ is Right to left 
            while(infix[i] == '^' && !s.empty() && s.top() == '^'){ 
                prefix += s.top();                                                               
                s.pop();
            }
            //We dont use >= sign here because if we do so the associativity of operators(except ^) becomes R-L (since the actual infix
            // expression is reversed)
            while(!s.empty() && precedence(s.top()) > precedence(infix[i])){
                prefix += s.top();
                s.pop();
            }  
            s.push(infix[i]);
        }
    }
    return prefix;
}

string InfixToPrefix(string infix){
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++){
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string prefix = InfixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}


int main(){
    string infix;
    cin >> infix;
   
    string prefix = InfixToPrefix(infix);
    string postfix = InfixToPostfix(infix);
    cout<<prefix<<endl;
    cout<<postfix<<endl;
    return 0;
}