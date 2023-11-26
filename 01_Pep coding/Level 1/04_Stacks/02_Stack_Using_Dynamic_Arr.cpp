
#include <iostream>
#include <cstdlib>
using namespace std;

class Stack{
    public :
        int top;
        int capacity;
        int *arr;
};

Stack* DoubleCapacity(Stack *S){
    S->capacity *= 2;
    S->arr = (int*)realloc(S->arr, S->capacity * sizeof(int));
    return S;
}

Stack* createStack(){
    Stack *s = new Stack;
    s->top = -1;
    s->capacity = 1;
    s->arr = new int[s->capacity];
    if(!s->arr)
        return NULL;
    return s;
}

bool isFull(Stack *S){
    if(S->top == S->capacity-1)
        return true;
    return false;
}

bool isEmpty(Stack *S){
    if(S->top == -1)
        return true;
    return false;
}

void push(Stack *S, int data){
    if(isFull)
        S = DoubleCapacity(S);
    S->arr[++S->top] = data;
}

int pop(Stack *S){
    if(isEmpty(S)){
        cout<<"Stack Underflow"<<endl;
        return INT_MIN;
    }
    else
        return S->arr[S->top--];
}

int peek(Stack *S){
    if(!isEmpty(S))
        return S->arr[S->top];
    return INT_MIN;
}

void displayStack(Stack *S){
    if(!isEmpty(S)){
        int idx = S->top;
        while(idx>=0){
            cout<<S->arr[idx]<<" ";
            idx--;
        }
        cout<<endl;
        return;
    }
    cout<<"Stack Empty"<<endl;
}

void deleteStack(Stack *S){
    if(!S){                 
        if(!S->arr){         
            delete S->arr;
            S->arr = NULL;
        }
        delete S;
        S = NULL; 
    }
    cout<<"Stack Wiped"<<endl;
}

int main(){
    Stack *sp = createStack();
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values 
    push(sp, 46); // Stack Overflow since the size of the stack is 10
    displayStack(sp);
    deleteStack(sp);
    return 0;
}