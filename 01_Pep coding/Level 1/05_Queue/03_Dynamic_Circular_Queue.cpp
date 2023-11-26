
#include <iostream>
using namespace std;

class queue{
        int data;
        int *arr;
        int front, rear, size = 2;
    public :
        queue(){
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
        void resize(){
            int s = size;
            size *= 2;
            arr = (int*)realloc(arr, size * sizeof(int));
            if(arr == NULL){
                cout<<"Error"<<endl;
                return;
            }
            if(front > rear){
                for(int i=0; i<=rear; i++){
                    arr[s+i] = arr[i];
                }
                rear = rear + s;
            }
        }
        void enQueue(int data){
            if(isFull()){
                resize();
            } 
            rear = (rear+1)%size;
            arr[rear] = data;
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
            int i=front+1;
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
        int rearr(){
            if(!isEmpty())
                return arr[rear];
            cout<<"Empty"<<endl;
            return INT_MIN;
        }
};

int main(){
    queue q;
    q.enQueue(10);
    q.enQueue(11);
    q.enQueue(12);
    q.enQueue(13);
    q.enQueue(14);
    q.enQueue(15);
    q.enQueue(16);
    q.enQueue(17);
    q.enQueue(18);
    q.enQueue(19);
    q.enQueue(20);
    cout<<"Queue : ";
    q.display();
    
    cout<<q.deQueue()<<" removed"<<endl;
    cout<<"Queue : ";
    q.display();

    cout<<"Front : "<<q.frontt()<<endl;
    cout<<"Rear : "<<q.rearr()<<endl;
    return 0;
}