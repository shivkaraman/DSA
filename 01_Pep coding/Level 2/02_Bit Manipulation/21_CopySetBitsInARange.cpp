/*
1. You are given two numbers A and B.
2. You are given two more numbers left and right, representing a range [left,right].
3. You have to set bits in B which are set in A lying in the above mentioned range.
4. Print the updated number B.

Sample Input
    10 13
    2  3
Sample Output
    15

*/


#include <iostream>
using namespace std;

void solution(int a, int b, int l, int r){
    int mask = (1 << (l-r+1)) - 1;
    mask = (mask << (r-1));
    mask = a & mask;
    cout << (b | mask) << endl;
}

int main(){
    int a, b;
    cin >> a >> b;

    int l, r;
    cin >> l >> r;

    solution(a, b, r, l);
    return 0;
}