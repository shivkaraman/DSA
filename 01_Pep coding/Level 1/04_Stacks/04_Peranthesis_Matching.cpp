
#include <iostream>
using namespace std;

class Stack {
    public : 
        char symbol;
        Stack *next;
};

Stack* createStack(){
    return NULL;
}

bool isFull(Stack *top){
    Stack *temp = new Stack;
    return (temp == NULL);
}

char isEmpty(Stack *top){
    if(top == NULL)
        return 'e';
    else    
        return top->symbol;
}

void push(Stack **top, char c){
    if(isFull(*top))   
        cout<<"Stack Overflow"<<endl;
    else{
        Stack *temp = new Stack;
        temp->symbol = c;
        temp->next = *top;
        *top = temp;
    }
}

void pop(Stack **top, char sym){
    if(isEmpty(*top) == 'e'){
        cout<<"Stack Undeflow"<<endl;
    }
    else if(sym == (*top)->symbol){
        Stack *temp = (*top)->next;
        delete *top;
        *top = temp;
    }
}

int main(){
    string s;
    cin>>s;
    Stack *S = createStack();
    for(int i=0; i<s.length(); i++){
        switch(s[i]){
            case '{':
            case '[':
            case '(':
                push(&S, s[i]); break;
            case '}' :
                pop(&S, '{'); break;
            case ']' :
                pop(&S, '['); break;
            case ')' :
                pop(&S, '('); break;
        }
    }
    char ch = isEmpty(S);
    Stack *temp = S;
    if(ch == 'e')
         cout<<"Perenthesis Matched"<<endl;

    while(ch != 'e'){
        switch(ch){
            case '{':
                cout<<"}"<<" missing"<<endl; break;
            case '[':
                cout<<"]"<<" missing"<<endl; break;
            case '(':
                cout<<")"<<" missing"<<endl; break;
        }
        temp = temp->next;
        ch = isEmpty(temp);
    }
    return 0;
}