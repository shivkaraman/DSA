
#include <iostream>
using namespace std;

class stack{
    public : 
        int top;
        int *arr;
        int capacity;
};

stack* createStack(){
    stack *s = new stack;
    if(!s)
        return NULL;
    s->capacity = 10;
    s->top = -1;
    s->arr = new int[s->capacity];
    return s;
}

bool isFull(stack *s){
    if(s->top == s->capacity - 1)
        return true;
    return false;
}

bool isEmpty(stack *s){
    if(s->top == -1)
        return true;
    return false;
}

void push(stack *s, int data){
    if(isFull(s))
        cout<<"stack overflow"<<endl;
    else{
        s->arr[++s->top] = data;
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        cout<<"stack underflow"<<endl;
        return INT_MIN;
    }
    else{
        return s->arr[s->top--];
    }
}

int peek(stack *s){
    if(!isEmpty(s))
        return s->arr[s->top];
    return INT_MIN;
}

void display(stack *s){
    if(isEmpty(s))
        cout<<"Stack Empty"<<endl;
    else{
        int idx = s->top;
        while(idx >= 0){
            cout<<s->arr[idx]<<" ";
            idx--;
        }
    }
}

int main(){
    stack *sp = createStack();
    display(sp);
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
    display(sp);
    return 0;
    return 0;
}