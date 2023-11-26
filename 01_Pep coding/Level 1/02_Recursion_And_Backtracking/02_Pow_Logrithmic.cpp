// 1. You are given a number x.
// 2. You are given another number n.
// 3. You are required to calculate x raised to the power n. Don't change the signature of power function.

// Note1 -> The previous version expects the call stack to be of n height. This function expects call function to be only log(n) high.

#include<iostream>
using namespace std;

int powerLogarithmic(int x,int n){      // T(n) = T(n/2)+1 --> O(logn)
    // write your code here
    if(n==0)
        return 1;
    
    int xpnb2 = powerLogarithmic(x,n/2);    //x to the power n by 2
    
    if(n%2==0)
        return (xpnb2*xpnb2);
    else
        return (x*xpnb2*xpnb2);
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}