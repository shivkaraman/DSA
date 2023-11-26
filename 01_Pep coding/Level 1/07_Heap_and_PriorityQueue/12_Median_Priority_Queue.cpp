/*

1. You are required to complete the code of our MedianPriorityQueue class. The class should mimic the behaviour of a PriorityQueue and give highest priority to median of it's data.
2. Here is the list of functions that you are supposed to complete
2.1. add -> Should accept new data.
2.2. remove -> Should remove and return median value, if available or print "Underflow" otherwise and return -1
2.3. peek -> Should return median value, if available or print "Underflow" otherwise and return -1
2.4. size -> Should return the number of elements available
3. Input and Output is managed for you.

Note -> If there are even number of elements in the MedianPriorityQueue, consider the smaller median as median value.

INPUT 
    add 10
    remove
    peek
    add 30
    remove
    peek
    peek
    add 20
    add 50
    peek
    add 40
    remove
    peek
    remove
    peek
    remove
    peek
    add 60
    peek
    quit

OUTPUT
    10
    Underflow
    30
    Underflow
    Underflow
    20
    40
    20
    20
    50
    50
    Underflow
    60
*/

#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue {
    public:
        priority_queue <int> left;                             //Max heap
        priority_queue <int, vector<int>, greater<int>> right; //Min heap
        void push(int val){
            if(!right.empty() && val > right.top())
                right.push(val);
            else
                left.push(val);
            while(left.size() - right.size() != 0 && left.size() - right.size() != 1){
                if(right.size() > left.size()){
                    left.push(right.top());
                    right.pop();
                }
                else{
                    right.push(left.top());
                    left.pop();
                }
            }
        }

        int pop(){
            if(left.empty()){
                cout<<"Underflow"<<endl;
                return -1;
            }
                
            int med  = left.top();
            left.pop();
            while(left.size() - right.size() != 0 && left.size() - right.size() != 1){
                if(right.size() > left.size()){
                    left.push(right.top());
                    right.pop();
                }
                else{
                    right.push(left.top());
                    left.pop();
                }
            }
            return med;
        }
        int top() {
            if(left.empty()){
                cout<<"Underflow"<<endl;
                return -1;
            }
            return left.top();
        }
        int size() {
            return left.size() + right.size();
        }
};

int main() {
    MedianPriorityQueue pq;

    string str;
    cin >> str;
    while (str != "quit") {
        if (str == "add") {
            int val;
            cin >> val;
            pq.push(val);
        }
        else if (str == "remove") {
            int val = pq.pop();
            if (val != -1) {
                cout << val << endl;
            }
        }
        else if (str == "peek") {
            int val = pq.top();
            if (val != -1) {
                cout << val << endl;
            }
        }
        else if (str == "size") {
            cout << pq.size() << endl;
        }
        cin >> str;
    }
    return 0;
}