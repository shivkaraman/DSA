// 1. You are given a pattern of upto 8 length containing characters 'i' and 'd'.
// 2. 'd' stands for decreasing and 'i' stands for increasing
// 3. You have to print the smallest number, using the digits 1 to 9 only without repetition, such that 
// the digit decreases following a 'd' and increases follwing an 'i'.

// e.g.
// d -> 21
// i -> 12
// ddd -> 4321
// iii -> 1234
// dddiddd -> 43218765
// iiddd -> 126543
// 
// https://www.youtube.com/watch?v=GOCbsY7Arw4&list=PL-Jc9J83PIiEyUGT3S8zPdTMYojwZPLUM&index=27

#include <iostream>
#include <stack>
using namespace std;

int main(){
    string str;
    cin>>str;

    stack<int> s;
    int count = 1;
    for(char &c : str){
        if(c == 'i'){
            s.push(count);
            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
        }
        else
            s.push(count);
        count++;
    }
    s.push(count);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}