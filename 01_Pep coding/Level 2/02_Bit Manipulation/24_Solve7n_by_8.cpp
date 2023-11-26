/*
1. You are given a number n.
2. You have to calculate the value of 7n/8 without using division and multiplication.

Sample Input
    15
Sample Output
    13

7n/8 = (8n-n)/8
*/


#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = (n << 8) - n;
    cout << (ans >> 3) << endl;
    return 0;
}

