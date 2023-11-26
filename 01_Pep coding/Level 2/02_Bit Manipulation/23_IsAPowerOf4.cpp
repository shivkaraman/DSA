
#include <iostream>
using namespace std;

//4^x = (2^2)^x = 2^2x -> ie we need to check if the number is even power of 2
bool isPowerOfFour(int n){
    int mask = 0b01010101010101010101010101010101;
    return (n > 0) && (n & (n-1)) == 0 && (n & mask) > 0;
}

int main(){
    int n;
    cin>>n;
    
    if(isPowerOfFour(n))
        cout<<"true";
    else 
        cout<<"false";
    
}