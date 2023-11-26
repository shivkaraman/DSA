/*
1. You are given a number n.
2. You have to count the number of set bits in the given number. 
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
  
    int count{};
    while(n){
        int rsbm = n & -n;
        n -= rsbm;
        count++;
    }
    cout << count << endl;
    return 0;
}