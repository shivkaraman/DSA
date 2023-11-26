/*
Q: Evalution of Infix Expression using Two Stacks.
Algo:  Here we have two stacks.
1) Operator Stack
2) Operand Stack.
Here we process the given infix expression string from left to right.
1) If we come across an operand , We push the operand into the Operand Stack.
2) If we come across an an operator, We follow the following algorithm for operators
*********
	Priority of operators
	^   --> 4
	*,/ --> 3
	+,- --> 2
	(   --> 1
	a) If the opeartor stack is empty, push the operator into the stack.
	b) If the opeartor stack is not empty, compare the priority of operator on the top of the stack to the current operator
	c) let t = priority of operator on the top of the stack, p = priority of current operator
	while(t >= p):
		pop(t)
	after poping all operators whose priority is greater than the current opeartor, push this operator on the stack.
	**. if the operator is ( just push in to the stack, with out considering priority.
	**. if the operator is ) , Pop the opeartors and append till we encounter matching (. don't add (,) to the output.
	After processing completing string. pop all the operators from stack
	
	*** When an operator is poped from the stack, perform calculation for the top two operands of opearand stack with this operator. 
  Push the result on to the operand stack .
	1+2*3+5
*/
                                      

#include <iostream>
#include <stack>
using namespace std;

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return -1;
}

int giveResult(int n1, int n2, char c){
    if(c == '*')
        return n1*n2;
    else if(c == '/')
         return n1/n2;
    else if(c == '+')
        return n1+n2;
    else
        return n1-n2;
}

int main(){
    stack<int> Oprnd;
    stack<char> Oper;
    string infix; 
    cin>>infix;
    infix = '(' + infix + ')';
    for(int i=0; i<infix.length(); i++){
        if(infix[i] == '('){
            Oper.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(Oper.top() != '('){
                char op = Oper.top();
                Oper.pop();
                int i2 = Oprnd.top();
                Oprnd.pop();
                int i1 = Oprnd.top();
                Oprnd.pop();
                int res = giveResult(i1, i2, op);
                Oprnd.push(res);
            }
            Oper.pop();
        }
        else if(isOperator(infix[i])){
            while(!Oper.empty() && precedence(infix[i]) <= precedence(Oper.top())){
                char op = Oper.top();
                Oper.pop();
                int i2 = Oprnd.top();
                Oprnd.pop();
                int i1 = Oprnd.top();
                Oprnd.pop();
                int res = giveResult(i1, i2, op);
                Oprnd.push(res);
            }
            Oper.push(infix[i]);
            
        }
        else    
            Oprnd.push(infix[i]-'0');
    }
	cout <<"Result: " << Oprnd.top() << endl;
    return 0;
}
