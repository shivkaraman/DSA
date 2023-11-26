/*
1. You are given a number n.
2. You have to swap all odd position bits with even position bits.
3. Every odd position bit is swapped with adjacent bit on left side.
4. Every even position bit is swapped with adjacent bit on right side.
5. Print the number formed after swapping.

Sample Input
    10
Sample Output
    5
*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int omask = 0x55555555;
    int emask = 0xAAAAAAAA;

    int oddBits = (n & omask); // This isolates odd bits of n
    int evenBits = (n & emask);// This isolates even bits of nNN
    oddBits  = oddBits << 1;
    evenBits = evenBits >> 1;
    n = oddBits | evenBits;

    cout << n << endl;

    return 0;
}

