
#include <iostream>
using namespace std;

class queue{
        int data;
        queue *next, *f, *r;
    public :
        queue(){
            f = r = next = NULL;
        }
        bool isEmpty(){
            if(f == NULL)
                return true;
            return false;
        }
        bool isFull(){
            queue *temp = new queue;
            if(temp == NULL)
                return true;
            delete temp;
            return false;
        }
        void enQueue(int data){
            if(isFull())
                cout<<"Overflow "<<data<<"cannot be enqueed"<<endl;
            else{
                queue *newNode = new queue;
                newNode->data = data;
                if(isEmpty())
                    f = r = newNode;
                else{
                    r->next = newNode;
                    r = newNode;
                }
            }
        }
        int deQueue(){
            int v;
            if(isEmpty()){
                cout<<"Underflow"<<endl;
                v = INT_MIN;
            }
            else{
                queue *temp = f;
                f = f->next;
                v = temp->data;
                delete temp;
            }
            return v;
        }
        int front(){
            if(!isEmpty())
                return f->data;
            cout<<"Empty"<<endl;
            return INT_MIN;
        }
        void dispay(){
            if(isEmpty()){
                cout<<"Empty"<<endl;
                return;
            }
            queue *ptr = f;
            while(ptr != NULL){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
};

int main(){
    queue q;
    q.enQueue(10);
    cout<<"Queue :";
    q.dispay();

    q.deQueue();
    cout<<"Queue :";
    q.dispay();
    return 0;
}