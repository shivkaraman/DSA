// 1. You are given a number x.
// 2. You are given another number n.
// 3. You are required to calculate x raised to the power n. Don't change the signature of power function .

#include <iostream>
using namespace std;
int power(int x , int n){   // T(n) = T(n-1)+1 --> O(n)
    if(n==0)    
        return 1;

    return(x * power(x,n-1));
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
    return 0;
}