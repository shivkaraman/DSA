
#include <iostream>
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

void pop(Stack **top){
    if(isEmpty(*top))
        cout<<"Stack Underflow"<<endl;
    else{
        Stack *temp = (*top)->next;
        delete *top;
        *top = temp;
    }
}

void displayStack(Stack *S){
    if(!S){
        cout<<"Stack Empty"<<endl;
        return;
    }
    while(S){
        cout<<S->data<<" ";
        S = S->next;
    }
    cout<<endl;
}

void deleteStack(Stack *S){      
    Stack *temp, *current = S;
    while(current){
        temp = current->next;
        delete current;
        current = temp;
    }
    cout<<"Stack Wiped"<<endl;
}

int main(){
    Stack *sp = createStack();
    push(&sp, 1);
    push(&sp, 23);
    push(&sp, 99);
    push(&sp, 75);
    push(&sp, 3);
    push(&sp, 64);
    push(&sp, 57);
    push(&sp, 46);
    push(&sp, 89);
    push(&sp, 6);  //Pushed 10 values 
    displayStack(sp);
    pop(&sp);
    displayStack(sp);
    deleteStack(sp);
    return 0;
}