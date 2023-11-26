//Design an algorithm to find min of a stack in O(1) time complexity
//Note that if stack is popped, the min element may change (if stack top is the min element)
/*
1. Create a stack of pair<int,int> 
2. Take first element as input and second element with min till now
3. In getMin function, return top.second 
*/

#include <iostream>
#include <stack>
using namespace std;

int getMin(stack<pair<int,int>> S){
    return S.top().second;
}
int main(){     //T = O(1)  S = O(N)
    stack<pair<int, int>> S;
    pair<int, int> data;
    int choice; 
    do{
        int x;
        cin>>x;
        data.first = x;
        if(S.empty())
            data.second = x;
        else{
            if(S.top().second < x)
                data.second = S.top().second;
            else    
                data.second = x;
        }
        S.push(data);
        cin>>choice;
    }while(choice);
    
    cout<<getMin(S)<<endl;
    S.pop();
    S.pop();
    cout<<getMin(S)<<endl;
    return 0;
}
//      min ele
//  4 0  -1
// -1 3  -1
//  2 1   1
//  1 1   1
