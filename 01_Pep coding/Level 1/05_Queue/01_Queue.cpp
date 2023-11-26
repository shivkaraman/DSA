
#include <iostream>
using namespace std;

class queue{
        int data;
        int *arr;
        int front, rear, size = 10;
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
            if(rear == size-1)
                return true;
            return false;
        }
        void enQueue(int data){
            if(isFull())
                cout<<"Overflow "<<data<<" cannot be enqueed"<<endl;
            else
                arr[++rear] = data;
        }
        int deQueue(){
            int val;
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                val = -1;
            }
            else{
                val = arr[++front];
            }
            return val;
        }
        int frontt(){
            if(!isEmpty())
                return arr[front+1];
            cout<<"Empty"<<endl;
            return INT_MIN;
        }
        void display(){
            if(isEmpty()){
                cout<<"Empty"<<endl;
                return;
            }
            for(int i=front+1; i<=rear; i++)
                cout<<arr[i]<<" ";
            cout<<endl;
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
    q.enQueue(20);  //Overflow

    cout<<"Queue : ";
    q.display();

    cout<<q.frontt()<<endl;
    return 0;
}