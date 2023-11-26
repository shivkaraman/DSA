/*
1. You are given a number n.
2. You have to print the count of set bits of first n natural numbers.

Sample Input
    17
Sample Output
    35

if highest power of 2 of n = x
ie n = 2^x + k

Sol(n) = (2^(x-1) * x) + (n - 2^x + 1) + sol(n - 2^x)
*/

#include<iostream>
using namespace std;

int highestPowOf2(int n){
    int pow = 0;
    while((1 << pow) <= n){
        pow++;
    }
    return pow-1;
}

int solution(int n){
    if(n == 0)
        return 0;  
    int x = highestPowOf2(n);
    int btill2x = x * (1 << (x - 1)); // Bits till 2^(x-1)
    int msb2xton = n - (1 << x) + 1;  // msb from 2^x to n=n-2^x+1
    int rest = n - (1 << x);          //rest of bits
    int ans = btill2x + msb2xton + solution(rest) ;
    return ans ;
}

int main(){
    int n;
    cin >> n;

    cout << solution(n);
    return 0;
}