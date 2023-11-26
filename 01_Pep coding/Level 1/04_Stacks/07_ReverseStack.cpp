//Reverse given stack

#include <iostream>
#include <stack>
using namespace std;

//Expectation--> data ko stack ke bottom me dalo
//Faith --> n-1 elements ke liye function data ko bottom me dalna janta hain
//E-F --> n-1 elements ke liye data ko bottom me dalo aur nth element ko stack ke upar push kardo
void InsertAtBottom(stack<int> &S, int data){
    if(S.empty()){
        S.push(data);
        return;
    }
    int x = S.top();
    S.pop();
    InsertAtBottom(S, data);
    S.push(x);
}

// E--> n elements ko reverse karo
// F--> n-1 elements ko reverse arna janta hain
// E-F->n-1 elements ko reverse karo aur nth element ko stack ke bottom me insert kardo
void reverse(stack<int> &S){
    if(S.empty())
        return;
    int top = S.top();
    S.pop();
    reverse(S);
    InsertAtBottom(S, top);
}

int main(){
    stack<int> S;
    int choice;
    do{
        int x;
        cin>>x;
        S.push(x);
        cin>>choice;
    }while(choice);
    reverse(S);
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
    return 0;
}