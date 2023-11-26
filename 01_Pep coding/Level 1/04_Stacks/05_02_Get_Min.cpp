/*
An approach that uses O(1) time and O(n) extra space is discussed here.

Push(x) : Inserts x at the top of stack. 
     If stack is empty, insert x into the stack and make minEle equal to x.
     If stack is not empty, compare x with minEle. Two cases arise:
        1. If x is greater than or equal to minEle, simply insert x.
        2. If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. 
        For example, let previous  minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 – 3 = 1 into the stack.

Pop() : Removes an element from top of stack. 
     Remove element from top. Let the removed element be y. Two cases arise:
        1. If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
        2. If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). 
     This is where we retrieve previous minimum from current minimum and its value in stack. 
     For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
How it works
In push :  IN here we check if the new value is lesser then minELe, if so, we modify the value and push to stack
                             x < minEle
                      x-minEle < 0
                     2x-minEle < 0 + x
                     2x-minEle < x
               ie modified val < newMinValue --> Here the modified value is lesser than the min value
   Therefore modified value is the only value that is less than minVal (which is the identity of modified value)

In pop: In here we check if the top is a modified value, if so we get the prev min by (top < minEle)
  we assign minEle = 2*minEle-top
                     2*minELe-mdified
                     2*minEle-2x-prevMinEle
                     2*minEle-2*minEle-prevMinEle
                     prevMinEle
   Therefore we get the prev min value
*/

#include <iostream>
#include <stack>
using namespace std;

int minEle;
void pop(stack<int> &S){
    if(S.top() < minEle)
        minEle = 2*minEle - S.top();

    S.pop();    
}

void push(stack<int> &S, int x){
    if(S.empty()){
        S.push(x);
        minEle = x;
    }
    else if(x < minEle){       
        S.push(2*x - minEle);
        minEle = x;
    }
    else{
        S.push(x);
    }
}
 
int getMin(stack<int> &S){
    return minEle;
}

int main(){
    stack<int> S;
    int choice; 
    do{
        int x;
        cin>>x;
        
        push(S,x);
        cin>>choice;
    }while(choice);
    
    cout<<getMin(S)<<endl;
    pop(S);
    pop(S);
    cout<<getMin(S)<<endl;
    return 0;
}
//      min ele
//  4 0  -1
// -1 3  -1
//  2 1   1
//  1 1   1