
#include <iostream>
using namespace std;

class Stack{
        int top1, top2;
        int capacity;
        int *arr;
    public :
        void createStack(){
            top1 = -1;
            top2 = 10;
            capacity = 10;
            arr = new int[10];
        }
        bool isEmpty(int x){
            if(x == 1 && top1 == -1)
                return true;
            else if(x == 2 && top2 == 10)
                return true;
            else
                return false;
        }
        bool isFull(){
            if(top1 == top2) 
                return true;
            else 
                return false;
        }
        void push(int data, int x){
            if(isFull()){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else if(x == 1)
                arr[++top1] = data;
            else
                arr[--top2] = data;
        }
        void pop(int x){
            if(isEmpty(x)){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            if(x == 1){
                cout<<arr[top1]<<" popped"<<endl;
                top1--;
            }
            else{
                cout<<arr[top2]<<" popped"<<endl;
                top2++;
            }
        }
        void displayStack(int x){
            if(x == 1){
                cout<<"Stack 1 : ";
                for(int i=top1; i>=0; i--)
                    cout<<arr[i]<<" ";
            }
            else{
                cout<<"Stack 2 : ";
                for(int i=top2; i<10; i++)
                    cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Stack S;
    S.createStack();
    int choice;
    do{
        int x;
        cin>>x;
        int n;
        cin>>n;
        S.push(x, n);
        cin>> choice;
    }while(choice);
    S.displayStack(1);
    S.displayStack(2);

    S.pop(1);
    S.displayStack(1);
    S.pop(2);
    S.displayStack(2);
    return 0;
}