/*
DeQueue -> Insertion and deletion possible from both ends
* There are two types of DeQueue
    1. Restrited input - Insertion from front NOT POSSIBLE
    2. Restrited output -  Deletion from rear NOT POSSIBLE
*/

#include <iostream>
using namespace std;

class DEqueue{
        int data;
        int *arr;
        int front, rear, size = 10;
    public :
        DEqueue(){
            arr = new int[size];
            front = rear = -1;
        }
        bool isEmpty(){
            if(front == rear)
                return true;
            return false;
        }
        bool isFull(){
            if(front == -1 && rear == size-1)
                return true;
            if((rear+1)%size == front)
                return true;
            return false;
        }
        void enqueueF(int data){
            if(isFull())
                cout<<"Overflow "<<data<<" cannot be enqueed"<<endl;
            else{
                if(front == -1){
                    arr[0] = data;
                    front = size - 1;
                    rear = 0;
                }
                else if(front == 0){
                    arr[front] = data;
                    front = size - 1;
                }
                else{
                    arr[front] = data;
                    front--;
                }
            }
        }
        void enqueueR(int data){
            if(isFull()){
                cout<<"Overflow "<<data<<" cannot be enqueed"<<endl;
            } 
            else{
                if(rear == -1){
                    front = size - 1;
                }
                rear = (rear+1)%size;
                arr[rear] = data;    
            }
        }
        int dequeueF(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return INT_MIN;
            }
            else{
                int val = arr[(front+1)%size];
                front = (front+1)%size;
                return val;
            }
        }
        int dequeueR(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return INT_MIN;
            }
            else{
                int val = arr[rear];
                if(rear == 0 && front != -1)
                    rear = size-1;
                else
                    rear--;
                return val;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"DEqueue Empty"<<endl;
                return;
            }            
            int i=(front+1)%size;
            do{
                cout<<arr[i]<<" ";
                i = (i+1)%size;
            }while(i != (rear+1)%size);
            cout<<endl;
        }
        int frontt(){
            if(!isEmpty())
                return arr[(front+1)%size];
            cout<<"Empty"<<endl;
            return INT_MIN;
        }
};

int main(){
    DEqueue q;
    q.enqueueF(10);
    cout<<"DEqueue : ";
    q.display();

    q.enqueueF(20);
    cout<<"DEqueue : ";
    q.display();

    q.enqueueR(20);
    cout<<"DEqueue : ";
    q.display();

    q.dequeueF();
    cout<<"DEqueue : ";
    q.display();

    q.dequeueR();
    cout<<"DEqueue : ";
    q.display();
    return 0;
}