// Given a posstfix exprission, print its result

#include <iostream>
#include <list>
using namespace std;

class Stack{
    public : 
        int data;
        Stack *next;
};

Stack* createStack(){
    return NULL;
}

bool isFull(Stack *S){
    Stack *temp = new Stack;
    if(temp == NULL)
        return true;
    else    
        return false; 
}

bool isEmpty(Stack *S){
    if(S == NULL)
        return true;
    return false;
}

void push(Stack **top, int data){
    if(isFull(*top))
        cout<<"Stack Overflow : "<<data<<" cannot be pushed into stack"<<endl;
    else{
        Stack *newNode = new Stack;
        newNode->data = data;
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(Stack **top){
    if(isEmpty(*top))
        return 0;
    else{
        int r = (*top)->data;
        Stack *temp = (*top)->next;
        delete *top;
        *top = temp;
        return r;
    }
}

void displayStack(Stack *S){
    if(!S){
        return;
    }
    while(S){
        cout<<S->data<<" ";
        S = S->next;
    }
    cout<<endl;
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
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

int PostfixEvaluation(Stack **S, string postfix){
    int i = 0, result = 0;
    while(i != postfix.length()){
        if(!isOperator(postfix[i]))
            push(S, postfix[i]-'0');
        else if(isOperator(postfix[i])){
            int i2 = pop(S);
            int i1 = pop(S);
            result = giveResult(i1, i2, postfix[i]);
            push(S, result);
        }
        i++;
    }
    return result;
}

int main(){
    Stack *S = createStack();
    string postfix; 
    cin>>postfix;
    cout<<PostfixEvaluation(&S, postfix)<<endl;
    delete S;
    S = NULL; 
    return 0;
}