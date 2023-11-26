// https://www.youtube.com/watch?v=_abDDg0Jw94&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// 1. Take input of an infix expression
// 2. while(For each  char of strinng)
//      1. If operand -> Output
//      2. If right peranthhesis -> Pop out all operators and output till left perenthesis is encountered and check if there is any 
//                                  print operator just b4 '(' (if any)
//      3. If opreator or left peranthesis -> If it has a lower priority than the prev operand, pop and output all operators 
//                                            and push the current operator into stack

#include <iostream>
#include <stack>
using namespace std;

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/' || ch == '^') 
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '^')
        return 4;
    else if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}

void infixToPostfix(string infix){
     stack<char> S;
     for(int i=0; i<infix.length(); i++){
        if(infix[i] == '('){
            S.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(S.top() != '('){
                cout<<S.top();
                S.pop();
            }
            S.pop();
        }//a+b*c
        else if(isOperator(infix[i])){
            while(!S.empty() && precedence(infix[i]) <= precedence(S.top())){
                cout<<S.top();
                S.pop();
            }
            S.push(infix[i]); 
        }
        else    
            cout<<infix[i];
    }
    while(!S.empty()){
        cout<<S.top();
        S.pop();
    }
} 

int main(){
    string infix; 
    getline(cin,infix);
    infixToPostfix(infix);
    return 0;
}