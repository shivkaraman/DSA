/*
1. You are given a number n, representing the number of people in a party.
2. You are given n strings of n length containing 0's and 1's
3. If there is a '1' in ith row, jth spot, then person i knows person j.
4. A celebrity is defined as somebody who knows no other person than himself but everybody else knows him.
5. If there is a celebrity print it's index otherwise print "none".

Note -> There can be only one celebrity.
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;

    string str[n];
    for(int i=0; i<n; i++){ 
        cin>>str[i];
    }

    stack<int> person;
    for(int i=0; i<n; i++){
        person.push(i);
    }
    for(int i=0; i<n-1; i++){
        int n2 = person.top();
        person.pop();
        int n1 = person.top();
        person.pop();
        if(str[n1][n2] == '1') //If n1 knows n2 -> n1 cannot be a celebrity
            person.push(n2);
        else
            person.push(n1);
    }
    //Checking if the last person left out is actually a celebrity or not
    int pot = person.top(); person.pop();
    for(int i=0; i<n; i++){
        if(i != pot){
            if(str[i][pot] != '1' || str[pot][i] != '0'){
                cout<<"none"<<endl;
                return 0;
            }
        }
    }
    cout<<pot<<endl;
    return 0;
}