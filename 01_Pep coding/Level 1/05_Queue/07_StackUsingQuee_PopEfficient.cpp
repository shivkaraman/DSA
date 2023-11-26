// Stack Using Queue(POP EFFICIENT)
//Pop and top->O(1)

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
            while(!mainQ.empty()){
                helperQ.push(mainQ.front());
                mainQ.pop();
            }
            mainQ.push(data);
            while(!helperQ.empty()){
                mainQ.push(helperQ.front());
                helperQ.pop();
            }
        }
        void pop(){
           cout<<mainQ.front()<<" popped"<<endl;
           mainQ.pop();
        }
        int top(){
            return mainQ.front();
        }

};

int main(){
    stackUsingQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"Top : "<<s.top()<<endl;
    s.pop();
    cout<<"Top : "<<s.top()<<endl;
    s.pop();
    cout<<"Top : "<<s.top()<<endl;
    return 0;
}