// Stack Using Queue(PUSH EFFICIENT)
// Note -> push and size should work in constant time. pop and top should work in linear time.

#include <iostream>
#include <queue>
using namespace std;

class stackUsingQueue{
        queue<int> mainQ;
        queue<int> helperQ;
    public : 
        int size(){
            return mainQ.size();
        }
        void push(int data){
            mainQ.push(data);
        }
        void pop(){
            while(mainQ.size() > 1){
                helperQ.push(mainQ.front());
                mainQ.pop();
            }
            cout<<mainQ.front()<<" popped"<<endl;
            mainQ.pop();
            while(!helperQ.empty()){
                mainQ.push(helperQ.front());
                helperQ.pop();
            }
        }
        int top(){
            while(mainQ.size() > 1){
                helperQ.push(mainQ.front());
                mainQ.pop();
            }
            int val = mainQ.front();
            mainQ.pop();
            while(!helperQ.empty()){
                mainQ.push(helperQ.front());
                helperQ.pop();
            }
            mainQ.push(val);
            return val;
        }

};

int main(){
    stackUsingQueue s;
    s.push(10);
    s.push(20);
    cout<<"Top : "<<s.top()<<endl;
    s.pop();
    cout<<"Top : "<<s.top()<<endl;
    return 0;
}