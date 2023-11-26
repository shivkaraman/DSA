
#include <iostream>
#include <stack>
using namespace std;

class stackToQueue{
        stack<int> mainS;
        stack<int> helperS;
    public : 
        int size(){
            return mainS.size();
        }
        void push(int data){
            mainS.push(data);
        }
        void pop(){
            while(mainS.size() > 1){
                helperS.push(mainS.top());
                mainS.pop();
            }
            cout<<mainS.top()<<" popped"<<endl;
            mainS.pop();
            while(!helperS.empty()){
                mainS.push(helperS.top());
                helperS.pop();
            }
        }
        int front(){
            while(mainS.size() > 1){
                helperS.push(mainS.top());
                mainS.pop();
            }
            int val = mainS.top();
            while(!helperS.empty()){
                mainS.push(helperS.top());
                helperS.pop();
            }
            return val;
        }
        int back(){
            return mainS.top();
        }
};

int main(){
    stackToQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Back : "<<q.back()<<endl;
    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Back :  "<<q.back()<<endl;
    return 0;
}