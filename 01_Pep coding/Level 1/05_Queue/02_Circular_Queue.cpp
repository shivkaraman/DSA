
#include <iostream>
using namespace std;

class queue{
        int *arr;
        int front, rear, size = 5;
    public :
        queue(){
            arr = new int[size];
            front = rear = 0;
        }
        bool isEmpty(){
            if(front == rear)
                return true;
            return false;
        }
        bool isFull(){
            if((rear+1)%size == front)
                return true;
            return false;
        }
        void enQueue(int data){
            if(isFull()){
                cout<<"Overflow "<<data<<" cannot be enqueed"<<endl;
            } 
            else{
                rear = (rear+1)%size;
                arr[rear] = data;
            }
        }
        int deQueue(){
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                return INT_MIN;
            }
            else{
                int val = arr[front+1];
                front = (front+1)%size;
                return val;
            }
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue Empty"<<endl;
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
    queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    cout<<"Queue : ";
    q.display();
    
    cout<<q.deQueue()<<" removed"<<endl;
    cout<<"Queue : ";
    q.display();

    q.enQueue(10);
    q.display();
    return 0;
}